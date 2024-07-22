/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:57:14 by tuta              #+#    #+#             */
/*   Updated: 2024/07/22 13:37:09 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "Default Cat Constructor called!" << std::endl;
	_type = "Cat";
}

Cat::Cat(std::string name) : Animal(name)
{
	std::cout << this->_type << " Cat Constructor called!" << std::endl;
	_type = "Cat";
}

Cat::Cat(Cat const &cat) : Animal(cat)
{
	std::cout << "Default Cat copy constructor called!" << std::endl;
	*this = cat; 
}

Cat &Cat::operator=(Cat const &cat)
{
	std::cout << "Cat Assignation Operator called!" << std::endl;
	if (this == &cat)
		return *this;
	this->_type = cat._type;
	this->_name = cat._name;
	return *this;
}

Cat::~Cat()
{
	std::cout << this->_type << " Cat Destructor called!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miau Miau" << std::endl;
}
