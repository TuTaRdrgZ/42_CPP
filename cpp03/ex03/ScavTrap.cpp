/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:05:59 by tuta              #+#    #+#             */
/*   Updated: 2024/07/20 13:50:29 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap)
{
	_hitPoints = scavtrap._hitPoints;
	_attackDamage = scavtrap._attackDamage;
	_energyPoints = scavtrap._energyPoints;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
	if (this == &scavtrap)
		return *this;
	_name = scavtrap._name;
	_hitPoints = scavtrap._hitPoints;
	_energyPoints = scavtrap._energyPoints;
	_attackDamage = scavtrap._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

bool ScavTrap::canAttack() const
{
    if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
    {
        if (this->_hitPoints <= 0)
            std::cout << this->_name << " can't do anything with " << this->_hitPoints << " hitPoints!" << std::endl;
        else
            std::cout << this->_name << " can't do anything with " << this->_energyPoints << " energyPoints!" << std::endl;
        return false;
    }
    return true;
}

void ScavTrap::attack(std::string const & target)
{
	if (canAttack())
	{
		std::cout << "ScavTrap " << _name << " attack " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
		if (_energyPoints <= 0)
		{
			_energyPoints = 0;
			std::cout << "Oh no, " << _name << " has no energy points left!!" << std::endl;
		}
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode." << std::endl;
}
