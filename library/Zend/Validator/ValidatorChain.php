<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Validator;

use Countable;
use Zend\Stdlib\PriorityQueue;

class ValidatorChain extends AbstractValidator implements Countable
{
    /**
     * Default priority at which validators are added
     */
    const DEFAULT_PRIORITY = 1;

    /**
     * Validator plugin manager that is used to add validators by name
     *
     * @var ValidatorPluginManager
     */
    protected $validatorPluginManager;

    /**
     * validator chain
     *
     * @var PriorityQueue|ValidatorInterface[]
     */
    protected $validators;

    /**
     * Constructor
     */
    public function __construct(ValidatorPluginManager $validatorPluginManager)
    {
        $this->validatorPluginManager = $validatorPluginManager;
        $this->validators             = new PriorityQueue();
    }

    /**
     * Return the count of attached validators
     *
     * @return int
     */
    public function count()
    {
        return count($this->validators);
    }

    /**
     * Attach a validator to the chain
     *
     * @param  ValidatorInterface|Callable $validator A Validator implementation or valid PHP callback
     * @param  int                         $priority Priority at which to enqueue validator; defaults to 1 (higher executes earlier)
     * @return void
     */
    public function attach(Callable $validator, $priority = self::DEFAULT_PRIORITY)
    {
        $this->validators->insert($validator, $priority);
    }

    /**
     * Remove a validator from the chain
     *
     * Note that this method needs to iterate through all the validators, so it can be slow
     *
     * @param  ValidatorInterface|Callable $validator
     * @return bool True if the validator was successfully removed, false otherwise
     */
    public function remove(Callable $validator)
    {
        foreach ($this->validators as $key => $value) {
            if ($validator === $value) {
                unset($this->validators[$key]);
                return true;
            }
        }

        return false;
    }

    /**
     * Attach a validator to the chain by its name (using the validator plugin manager)
     *
     * @param  string $name Valid name
     * @param  int    $priority Priority at which to enqueue validator; defaults to 1 (higher executes earlier)
     * @return void
     */
    public function attachByName($name, $priority = self::DEFAULT_PRIORITY)
    {
        $validator = $this->validatorPluginManager->get($name);
        $this->validators->insert($validator, $priority);
    }

    /**
     * Remove a validator from the chain by its name
     *
     * Note that this method needs to get the FQCN from the name and iterate through all validators. This
     * can be really slow if validator chain contains a lot of validators
     *
     * @param  string $name
     * @return bool True if the validator was successfully removed, false otherwise
     */
    public function removeByName($name)
    {
        $className = array_search($name, $this->validatorPluginManager->getCanonicalNames());

        if ($className === false) {
            return false;
        }

        foreach ($this->validators as $key => $value) {
            if ('\\' . $className instanceof $value) {
                unset($this->validators[$key]);
                return true;
            }
        }

        return false;
    }

    /**
     * Merge the validator chain with the one given in parameter
     *
     * @param  ValidatorChain $validatorChain
     * @return void
     */
    public function merge(ValidatorChain $validatorChain)
    {
        foreach ($validatorChain->validators->toArray(PriorityQueue::EXTR_BOTH) as $item) {
            $this->attach($item['data'], $item['priority']);
        }
    }

    /**
     * Get all the validators
     *
     * @return PriorityQueue|ValidatorInterface[]
     */
    public function getValidators()
    {
        return $this->validators;
    }

    /**
     * Validate the value against all validators. Validators are run according to priority
     *
     * {@inheritDoc}
     */
    public function validate($value)
    {
        // @TODO
    }

    /**
     * Clone validators
     */
    public function __clone()
    {
        $this->validators = clone $this->validators;
    }
}
