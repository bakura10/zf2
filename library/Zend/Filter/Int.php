<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Filter;

/**
 * Filter that cast any value to an int
 */
class Int extends AbstractFilter
{
    /**
     * Returns (int) $value
     *
     * {@inheritDoc}
     */
    public function filter($value)
    {
        return (int) $value;
    }
}
