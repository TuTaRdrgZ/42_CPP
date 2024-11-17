/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:54:24 by tuta              #+#    #+#             */
/*   Updated: 2024/11/17 14:34:10 by tuta             ###   ########.fr       */
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
	if (canAttack())
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
	if (canAttack())
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

bool ClapTrap::canAttack() const
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
