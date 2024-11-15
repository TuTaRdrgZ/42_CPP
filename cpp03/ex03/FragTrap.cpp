/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:33:15 by tuta              #+#    #+#             */
/*   Updated: 2024/11/15 13:04:54 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap "<< this->_name << " constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& fragtrap) : ClapTrap(fragtrap)
{
	_hitPoints = fragtrap._hitPoints;
	_attackDamage = fragtrap._attackDamage;
	_energyPoints = fragtrap._energyPoints;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this == &fragtrap)
		return *this;
	_name = fragtrap._name;
	_hitPoints = fragtrap._hitPoints;
	_energyPoints = fragtrap._energyPoints;
	_attackDamage = fragtrap._attackDamage;
	return *this;
}

bool FragTrap::canAttack(FragTrap fragtrap)
{
	if (fragtrap.getHitPoints() <= 0 || fragtrap.getEnergyPoints() <= 0)
	{
		if (fragtrap.getHitPoints() <= 0)
			std::cout << fragtrap.getName() << " cant do anything with " << fragtrap.getHitPoints() << " hitPoints!" << std::endl;
		else
			std::cout << fragtrap.getName() << " cant do anything with " << fragtrap.getEnergyPoints() << " energyPoints!" << std::endl;
		return false;
	}
	return true;
}

void FragTrap::attack(std::string const &target)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap "<< this->_name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << this->_name << " really wanna highFive you <3" << std::endl;
}
