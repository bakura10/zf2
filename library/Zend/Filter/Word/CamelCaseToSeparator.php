<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Filter\Word;

use Zend\Stdlib\StringUtils;

/**
 * Filter that transforms camelCased words to custom separator (eg.: myExample to my:example)
 */
class CamelCaseToSeparator extends AbstractSeparator
{
    /**
     * {@inheritDoc}
     */
    public function filter($value)
    {
        if (StringUtils::hasPcreUnicodeSupport()) {
            $pattern     = array('#(?<=(?:\p{Lu}))(\p{Lu}\p{Ll})#', '#(?<=(?:\p{Ll}|\p{Nd}))(\p{Lu})#');
            $replacement = array($this->separator . '\1', $this->separator . '\1');
        } else {
            $pattern     = array('#(?<=(?:[A-Z]))([A-Z]+)([A-Z][A-z])#', '#(?<=(?:[a-z0-9]))([A-Z])#');
            $replacement = array('\1' . $this->separator . '\2', $this->separator . '\1');
        }

        return preg_replace($pattern, $replacement, $value);
    }
}
