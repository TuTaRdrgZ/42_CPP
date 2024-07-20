/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:54:24 by tuta              #+#    #+#             */
/*   Updated: 2024/07/20 13:21:04 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

bool canAttack(ClapTrap claptrap);

ClapTrap::ClapTrap() : _name("default ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	_name = clapTrap._name;
	_hitPoints = clapTrap._hitPoints;
	_energyPoints = clapTrap._energyPoints;
	_attackDamage = clapTrap._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
	if (canAttack(*this))
	{
		std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
		if (_energyPoints <= 0)
		{
			_energyPoints = 0;
			std::cout << "Oh no, " << _name << " has no energy points left!!" << std::endl;
		}
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " take " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (canAttack(*this))
	{
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " be repaired " << amount << " points of damage!" << std::endl;
		_energyPoints--;
		if (_energyPoints <= 0)
		{
			_energyPoints = 0;
			std::cout << "Oh no, " << _name << " has no energy points left!!" << std::endl;
		}
	}
}

int ClapTrap::getHitPoints()
{
	return _hitPoints;
}

int ClapTrap::getEnergyPoints()
{
	return _energyPoints;
}

int ClapTrap::getAttackDamage()
{
	return _attackDamage;
}

std::string ClapTrap::getName()
{
	return _name;
}

bool ClapTrap::canAttack(ClapTrap claptrap)
{
	if (claptrap.getHitPoints() <= 0 || claptrap.getEnergyPoints() <= 0)
	{
		if (claptrap.getHitPoints() <= 0)
			std::cout << claptrap.getName() << " cant do anything with " << claptrap.getHitPoints() << " hitPoints!" << std::endl;
		else
			std::cout << claptrap.getName() << " cant do anything with " << claptrap.getEnergyPoints() << " energyPoints!" << std::endl;
		return false;
	}
	return true;
}
