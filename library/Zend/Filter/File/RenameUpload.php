<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Filter\File;

use Zend\Filter\AbstractFilter;
use Zend\Filter\Exception;
use Zend\Stdlib\ErrorHandler;

/**
 * Filter that rename a file (and optionally move it to another location)
 */
class RenameUpload extends AbstractFilter
{
    /**
     * Destination target
     *
     * @var string|null
     */
    protected $target = null;

    /**
     * @var bool
     */
    protected $useUploadName = false;

    /**
     * @var bool
     */
    protected $useUploadExtension = false;

    /**
     * @var bool
     */
    protected $overwrite = false;

    /**
     * @var bool
     */
    protected $randomize = false;

    /**
     * Store already filtered values, so we can filter multiple
     * times the same file without being blocked by move_uploaded_file
     * internal checks
     *
     * @var array
     */
    protected $alreadyFiltered = array();

    /**
     * Set the target destination
     *
     * @param  string $target Target file path or directory
     * @throws Exception\InvalidArgumentException
     * @return void
     */
    public function setTarget($target)
    {
        if (!is_string($target)) {
            throw new Exception\InvalidArgumentException(
                'Invalid target, must be a string'
            );
        }

        $this->target = $target;
    }

    /**
     * Get the target destination
     *
     * @return string Target file path or directory
     */
    public function getTarget()
    {
        return $this->target;
    }

    /**
     * Set if the filter should use the upload name
     *
     * @param  bool $useUploadName When true, this filter will use the $_FILES['name']
     *                             as the target filename. Otherwise, it uses the default 'target' rules.
     * @return void
     */
    public function setUseUploadName($useUploadName)
    {
        $this->useUploadName = (bool) $useUploadName;
    }

    /**
     * @return bool
     */
    public function getUseUploadName()
    {
        return $this->useUploadName;
    }

    /**
     * @param  bool $useUploadExtension When true, this filter will use the original file
     *                                  extension for the target filename
     * @return void
     */
    public function setUseUploadExtension($useUploadExtension)
    {
        $this->useUploadExtension = (bool) $useUploadExtension;
    }

    /**
     * @return bool
     */
    public function getUseUploadExtension()
    {
        return $this->useUploadExtension;
    }

    /**
     * @param  bool $overwrite Shall existing files be overwritten?
     * @return void
     */
    public function setOverwrite($overwrite)
    {
        $this->overwrite = (bool) $overwrite;
    }

    /**
     * @return bool
     */
    public function getOverwrite()
    {
        return $this->overwrite;
    }

    /**
     * @param  bool $randomize Shall target files have a random postfix attached?
     * @return void
     */
    public function setRandomize($randomize = true)
    {
        $this->randomize = (bool) $randomize;
    }

    /**
     * @return bool
     */
    public function getRandomize()
    {
        return $this->randomize;
    }

    /**
     * Defined by Zend\Filter\Filter
     *
     * Renames the file $value to the new name set before
     * Returns the file $value, removing all but digit characters
     *
     * @param  string|array $value Full path of file to change or $_FILES data array
     * @throws Exception\RuntimeException
     * @return string|array The new filename which has been set, or false when there were errors
     */
    public function filter($value)
    {
        // An uploaded file? Retrieve the 'tmp_name'
        $isFileUpload = (is_array($value) && isset($value['tmp_name']));

        if ($isFileUpload) {
            $uploadData = $value;
            $sourceFile = $value['tmp_name'];
        } else {
            $uploadData = array(
                'tmp_name' => $value,
                'name'     => $value,
            );
            $sourceFile = $value;
        }

        if (isset($this->alreadyFiltered[$sourceFile])) {
            return $this->alreadyFiltered[$sourceFile];
        }

        $targetFile = $this->getFinalTarget($uploadData);
        if (!file_exists($sourceFile) || $sourceFile === $targetFile) {
            return $value;
        }

        $this->checkFileExists($targetFile);
        $this->moveUploadedFile($sourceFile, $targetFile);

        $return = $targetFile;
        if ($isFileUpload) {
            $return = $uploadData;
            $return['tmp_name'] = $targetFile;
        }

        $this->alreadyFiltered[$sourceFile] = $return;

        return $return;
    }

    /**
     * @param  string $sourceFile Source file path
     * @param  string $targetFile Target file path
     * @throws \Zend\Filter\Exception\RuntimeException
     * @return bool
     */
    protected function moveUploadedFile($sourceFile, $targetFile)
    {
        ErrorHandler::start();
        $result = move_uploaded_file($sourceFile, $targetFile);
        $warningException = ErrorHandler::stop();
        if (!$result || null !== $warningException) {
            throw new Exception\RuntimeException(
                sprintf("File '%s' could not be renamed. An error occurred while processing the file.", $sourceFile),
                0, $warningException
            );
        }

        return $result;
    }

    /**
     * @param  string $targetFile Target file path
     * @throws \Zend\Filter\Exception\InvalidArgumentException
     */
    protected function checkFileExists($targetFile)
    {
        if (file_exists($targetFile)) {
            if ($this->getOverwrite()) {
                unlink($targetFile);
            } else {
                throw new Exception\InvalidArgumentException(
                    sprintf("File '%s' could not be renamed. It already exists.", $targetFile)
                );
            }
        }
    }

    /**
     * @param  array $uploadData $_FILES array
     * @return string
     */
    protected function getFinalTarget($uploadData)
    {
        $source = $uploadData['tmp_name'];
        $target = $this->getTarget();

        if (!isset($target) || $target == '*') {
            $target = $source;
        }

        // Get the target directory
        if (is_dir($target)) {
            $targetDir = $target;
            $last      = $target[strlen($target) - 1];
            if (($last != '/') && ($last != '\\')) {
                $targetDir .= DIRECTORY_SEPARATOR;
            }
        } else {
            $info      = pathinfo($target);
            $targetDir = $info['dirname'] . DIRECTORY_SEPARATOR;
        }

        // Get the target filename
        if ($this->getUseUploadName()) {
            $targetFile = basename($uploadData['name']);
        } elseif (!is_dir($target)) {
            $targetFile = basename($target);
            if ($this->getUseUploadExtension() && !$this->getRandomize()) {
                $targetInfo = pathinfo($targetFile);
                $sourceinfo = pathinfo($uploadData['name']);
                if (isset($sourceinfo['extension'])) {
                    $targetFile = $targetInfo['filename'] . '.' . $sourceinfo['extension'];
                }
            }
        } else {
            $targetFile = basename($source);
        }

        if ($this->getRandomize()) {
            $targetFile = $this->applyRandomToFilename($uploadData['name'], $targetFile);
        }

        return $targetDir . $targetFile;
    }

    /**
     * @param  string $source
     * @param  string $filename
     * @return string
     */
    protected function applyRandomToFilename($source, $filename)
    {
        $info = pathinfo($filename);
        $filename = $info['filename'] . uniqid('_');

        $sourceInfo = pathinfo($source);

        $extension = '';
        if ($this->getUseUploadExtension() === true && isset($sourceInfo['extension'])) {
            $extension .= '.' . $sourceInfo['extension'];
        } elseif (isset($info['extension'])) {
            $extension .= '.' . $info['extension'];
        }

        return $filename . $extension;
    }
}
