<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\InputFilter;

use RecursiveIterator;
use Zend\InputFilter\Filter\AbstractValidationGroupFilter;

/**
 * Input collection interface
 */
interface InputCollectionInterface extends RecursiveIterator
{
    /**
     * Set the name of the input collection
     *
     * @param  string $name
     * @return void
     */
    public function setName($name);

    /**
     * Get the name of the input collection
     *
     * @return string
     */
    public function getName();

    /**
     * Add an input or another input collection (if no name was set, it will extract the one set in
     * the input or input collection)
     *
     * @param  InputInterface|InputCollectionInterface|array $inputOrInputCollection
     * @param  string|null                                   $name
     * @return void
     */
    public function add($inputOrInputCollection, $name = null);

    /**
     * Get an input or an input collection by name
     *
     * @param  string $name
     * @return InputInterface|InputCollectionInterface
     */
    public function get($name);

    /**
     * Check if the input collection contains an input or another input collection with the name given
     *
     * @param  string $name
     * @return bool
     */
    public function has($name);

    /**
     * Remove the input or input collection from the given name
     *
     * @param  string $name
     * @return void
     */
    public function remove($name);

    /**
     * Set the validation group filter
     *
     * @param  AbstractValidationGroupFilter $validationGroupFilter
     * @return void
     */
    public function setValidationGroupFilter(AbstractValidationGroupFilter $validationGroupFilter);

    /**
     * Get the validation group filter
     *
     * @return AbstractValidationGroupFilter
     */
    public function getValidationGroupFilter();

    /**
     * Check if the input filter is valid
     *
     * @param  array      $data     Data to validate
     * @param  mixed|null $context  An optional context used for validation
     * @return Result\ValidationResultInterface
     */
    public function validate(array $data, $context = null);
}
