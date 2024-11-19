/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:57:14 by tuta              #+#    #+#             */
/*   Updated: 2024/11/19 22:05:55 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Default Cat Constructor called!" << std::endl;
}

Cat::Cat(Cat const &cat) : Animal(cat)
{
	_brain = new Brain(*cat._brain);
	std::cout << "Default Cat copy constructor called!" << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
	std::cout << "Cat Assignation Operator called!" << std::endl;
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	delete (_brain);
	_brain = new Brain(*other._brain);
	return (*this);
}

Cat::~Cat()
{
	std::cout << this->_type << " Cat Destructor called!" << std::endl;
	delete _brain;
}

void Cat::makeSound() const
{
	std::cout << "Miau Miau" << std::endl;
}
