<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Filter\Word;

/**
 * Filter that underscore_separated words to dashed-separated words (eg.: my_example to my-example)
 */
class UnderscoreToDash extends SeparatorToSeparator
{
    /**
     * Constructor
     *
     */
    public function __construct()
    {
        parent::__construct(array(
            'search_separator'      => '_',
            'replacement_separator' => '-'
        ));
    }
}
