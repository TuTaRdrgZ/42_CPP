/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:57:01 by tuta              #+#    #+#             */
/*   Updated: 2024/07/22 15:38:09 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() :Animal("Dog")
{
	std::cout << "Default Dog Constructor called!" << std::endl;
	_type = "Dog";
	_brain = new Brain();
	if (_brain == NULL)
	{
		std::cout << "Error: Memory could not be allocated" << std::endl;
		exit(1);
	}
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << this->_type << " Dog Constructor called!" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	std::cout << "Default Dog copy constructor called!" << std::endl;
	*this = dog; 
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Dog Assignation Operator called!" << std::endl;
	if (this == &dog)
		return *this;
	this->_type = dog._type;
	this->_name = dog._name;
	this->_brain = new Brain(*dog._brain);
	return *this;
}

Dog::~Dog()
{
	std::cout << this->_type << " Dog Destructor called!" << std::endl;
	delete _brain;
}

void Dog::makeSound() const
{
	std::cout << "Bark Bark" << std::endl;
}
