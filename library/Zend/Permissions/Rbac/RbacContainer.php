<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Permissions\Rbac;

/**
 * A RBAC container is just here to store roles and avoid any duplicate
 */
class RbacContainer
{
    /**
     * List of roles
     *
     * @var array|RoleInterface[]
     */
    protected $roles = [];

    /**
     * Add a role to the container
     *
     * @param  RoleInterface $role
     * @return void
     * @throws Exception\InvalidArgumentException
     */
    public function addRole(RoleInterface $role)
    {
        // If the role is already registered we throw an exception, as it could be a potential security issue
        // to have two roles with same name
        if ($this->hasRole($role)) {
            throw new Exception\InvalidArgumentException(sprintf(
                'A role with name "%s" already exists in the container',
                $role->getName()
            ));
        }

        $this->roles[(string) $role] = $role;
    }

    /**
     * Is a role with the same name already registered?
     *
     * @param  RoleInterface|string $role
     * @return bool
     */
    public function hasRole($role)
    {
        return isset($this->roles[(string) $role]);
    }

    /**
     * Get a role by its name
     *
     * @param  string $name
     * @return RoleInterface|null
     */
    public function getRole($name)
    {
        if (isset($this->roles[$name])) {
            return $this->roles[$name];
        }

        return null;
    }

    /**
     * Determines if access is granted by checking the role and child roles for permission.
     *
     * @param  RoleInterface                    $role
     * @param  string                           $permission
     * @param  AssertionInterface|Callable|null $assert
     * @throws Exception\InvalidArgumentException
     * @return bool
     */
    public function isGranted(RoleInterface $role, $permission, $assert = null)
    {
        if ($assert) {
            if ($assert instanceof AssertionInterface) {
                if (!$assert->assert($this)) {
                    return false;
                }
            } elseif (is_callable($assert)) {
                if (!$assert($this)) {
                    return false;
                }
            } else {
                throw new Exception\InvalidArgumentException(
                    'Assertions must be a callable or an instance of Zend\Permissions\Rbac\AssertionInterface'
                );
            }
        }

        return $role->hasPermission($permission);
    }
}
