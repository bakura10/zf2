<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\InputFilter\Filter;

use Zend\InputFilter\InputCollectionInterface;

/**
 * Validation group filter based on a Regex. The validation group array that may be defined in
 * the input collection is therefore silently ignored
 */
class ValidationGroupRegexFilter extends AbstractValidationGroupFilter
{
    /**
     * @var string
     */
    protected $regex;

    /**
     * @param InputCollectionInterface $recursiveIterator
     * @param string                   $regex
     */
    public function __construct(InputCollectionInterface $recursiveIterator, $regex)
    {
        parent::__construct($recursiveIterator);
        $this->regex = (string) $regex;
    }

    /**
     * {@inheritDoc}
     */
    public function accept()
    {
        return (bool) preg_match($this->regex, $this->key());
    }
}
