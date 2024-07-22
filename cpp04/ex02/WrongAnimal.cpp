/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:26:08 by tuta              #+#    #+#             */
/*   Updated: 2024/07/22 14:27:03 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout << "Default WrongAnimal Constructor called!" << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << this->_type << " WrongAnimal Constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	std::cout << "Default WrongAnimal copy constructor called!" << std::endl;
	*this = animal; 
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
	std::cout << "WrongAnimal Assignation Operator called!" << std::endl;
	if (this == &animal)
		return *this;
	this->_type = animal._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << this->_type << " WrongAnimal Destructor called!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}

void WrongAnimal::setType(std::string type)
{
	this->_type = type;
}

std::string WrongAnimal::getName() const
{
	return this->_name;
}

void WrongAnimal::setName(std::string name)
{
	this->_name = name;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Noices" << std::endl;
}
