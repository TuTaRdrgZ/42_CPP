/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:26:08 by tuta              #+#    #+#             */
/*   Updated: 2024/11/24 13:37:52 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Default Animal Constructor called!" << std::endl;
	this->_type = "Animal";
}

Animal::Animal(const std::string& type) : _type(type)
{
	std::cout << this->_type << " Animal Constructor called!" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Default Animal copy constructor called!" << std::endl;
	*this = animal; 
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "Animal Assignation Operator called!" << std::endl;
	if (this == &animal)
		return *this;
	this->_type = animal._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << this->_type << " Animal Destructor called!" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal Noices" << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}

void Animal::setType(std::string type)
{
	this->_type = type;
}
