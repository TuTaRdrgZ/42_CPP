/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:57:01 by tuta              #+#    #+#             */
/*   Updated: 2024/11/19 21:22:39 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() :Animal("Dog")
{
	std::cout << "Default Dog Constructor called!" << std::endl;
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
	return *this;
}

Dog::~Dog()
{
	std::cout << this->_type << " Dog Destructor called!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bark Bark" << std::endl;
}
