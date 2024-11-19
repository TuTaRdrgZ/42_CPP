/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:57:01 by tuta              #+#    #+#             */
/*   Updated: 2024/11/19 22:06:20 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() :Animal("Dog")
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Default Dog Constructor called!" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	_brain = new Brain(*dog._brain);
	std::cout << "Default Dog copy constructor called!" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog Assignation Operator called!" << std::endl;
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	delete (_brain);
	_brain = new Brain(*other._brain);
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << this->_type << " Dog Destructor called!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bark Bark" << std::endl;
}
