/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:33:15 by tuta              #+#    #+#             */
/*   Updated: 2024/11/17 14:20:06 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default diamondtrap"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_name = "Default diamondtrap";
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap "<< this->_name << " constructor called" << std::endl;
	this->_name = name;
	FragTrap::_hitPoints = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap) : ClapTrap(diamondtrap), ScavTrap(diamondtrap), FragTrap(diamondtrap)
{
	_hitPoints = diamondtrap._hitPoints;
	_attackDamage = diamondtrap._attackDamage;
	_energyPoints = diamondtrap._energyPoints;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	if (this == &diamondtrap)
		return *this;
	_name = diamondtrap._name;
	_hitPoints = diamondtrap._hitPoints;
	_energyPoints = diamondtrap._energyPoints;
	_attackDamage = diamondtrap._attackDamage;
	return *this;
}

bool DiamondTrap::canAttack() const
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

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap "<< this->_name << " destructor called" << std::endl;
}

void DiamondTrap::highFivesGuys()
{
	std::cout << this->_name << " really wanna highFive you <3" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I'm " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
