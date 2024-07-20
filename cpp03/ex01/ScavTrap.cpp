/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:05:59 by tuta              #+#    #+#             */
/*   Updated: 2024/07/20 13:24:36 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

bool ScavTrap::canAttack(ScavTrap scavtrap)
{
	if (scavtrap.getHitPoints() <= 0 || scavtrap.getEnergyPoints() <= 0)
	{
		if (scavtrap.getHitPoints() <= 0)
			std::cout << scavtrap.getName() << " cant do anything with " << scavtrap.getHitPoints() << " hitPoints!" << std::endl;
		else
			std::cout << scavtrap.getName() << " cant do anything with " << scavtrap.getEnergyPoints() << " energyPoints!" << std::endl;
		return false;
	}
	return true;
}

void ScavTrap::attack(std::string const & target)
{
	if (canAttack(*this))
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
