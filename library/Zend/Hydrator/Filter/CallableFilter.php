<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Hydrator\Filter;

/**
 * This filter evaluates a Callable
 */
class CallableFilter implements FilterInterface
{
    /**
     * @var Callable
     */
    protected $callable;

    /**
     * @param Callable $callable
     */
    public function __construct(Callable $callable)
    {
        $this->callable = $callable;
    }

    /**
     * {@inheritDoc}
     */
    public function filter($property)
    {
        return call_user_func($this->callable, $property);
    }
}
