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
 * Validation group filter based on a callback. The validation group array that may be defined in
 * the input collection is therefore silently ignored
 *
 * The callback must accept three parameters: the first one is the current item's value (the input instance), the second
 * one is the current item's key (the input's name), and the third one is the Iterator instance that is being filtered
 */
class ValidationGroupCallbackFilter extends AbstractValidationGroupFilter
{
    /**
     * @var Callable
     */
    protected $callback;

    /**
     * @param InputCollectionInterface $recursiveIterator
     * @param Callable                 $callback
     */
    public function __construct(InputCollectionInterface $recursiveIterator, Callable $callback)
    {
        parent::__construct($recursiveIterator);
        $this->callback = $callback;
    }

    /**
     * {@inheritDoc}
     */
    public function accept()
    {
        return (bool) $this->callback($this->current(), $this->key(), $this->getInnerIterator());
    }
}
