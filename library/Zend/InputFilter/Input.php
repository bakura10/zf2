<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\InputFilter;

use Zend\InputFilter\Result\ValidationResult;
use Zend\Validator\ValidatorChain;
use Zend\Filter\FilterChain;

/**
 * Input
 */
class Input implements InputInterface
{
    /**
     * @var string
     */
    protected $name;

    /**
     * @var bool
     */
    protected $required = false;

    /**
     * @var bool
     */
    protected $allowEmpty = false;

    /**
     * @var bool
     */
    protected $breakOnFailure = false;

    /**
     * @var FilterChain
     */
    protected $filterChain;

    /**
     * @var ValidatorChain
     */
    protected $validatorChain;

    /**
     * @param FilterChain|null    $filterChain
     * @param ValidatorChain|null $validatorChain
     */
    public function __construct(FilterChain $filterChain = null, ValidatorChain $validatorChain = null)
    {
        $this->filterChain    = $filterChain ?: new FilterChain();
        $this->validatorChain = $validatorChain ?: new ValidatorChain();
    }

    /**
     * {@inheritDoc}
     */
    public function setName($name)
    {
        $this->name = $name;
    }

    /**
     * {@inheritDoc}
     */
    public function getName()
    {
        return $this->name;
    }

    /**
     * {@inheritDoc}
     */
    public function setRequired($required)
    {
        if ($required) {
            // @TODO: refactor validator to allow to set priority
            $this->validatorChain->attachByName('NotEmpty');
        }
    }

    /**
     * {@inheritDoc}
     */
    public function isRequired()
    {
        return $this->required;
    }

    /**
     * {@inheritDoc}
     */
    public function setAllowEmpty($allowEmpty)
    {
        $this->allowEmpty = (bool) $allowEmpty;
    }

    /**
     * {@inheritDoc}
     */
    public function allowEmpty()
    {
        return $this->allowEmpty;
    }

    /**
     * {@inheritDoc}
     */
    public function setBreakOnFailure($breakOnFailure)
    {
        $this->breakOnFailure = (bool) $breakOnFailure;
    }

    /**
     * {@inheritDoc}
     */
    public function breakOnFailure()
    {
        return $this->breakOnFailure;
    }

    /**
     * {@inheritDoc}
     */
    public function getFilterChain()
    {
        return $this->filterChain;
    }

    /**
     * {@inheritDoc}
     */
    public function getValidatorChain()
    {
        return $this->validatorChain;
    }

    /**
     * {@inheritDoc}
     */
    public function validate($value, $context = null)
    {
        if (
            $this->validatorChain->isValid($value, $context)
            || (empty($value) && $this->allowEmpty)
        ) {
            return new ValidationResult($value);
        }

        return new ValidationResult($value, null, $this->validatorChain->getMessages());
    }
}
