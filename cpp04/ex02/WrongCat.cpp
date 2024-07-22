/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:32:15 by tuta              #+#    #+#             */
/*   Updated: 2024/07/22 14:33:45 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Default WrongCat Constructor called!" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(std::string name) : WrongAnimal(name)
{
	std::cout << this->_type << " WrongCat Constructor called!" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &cat) : WrongAnimal(cat)
{
	std::cout << "Default WrongCat copy constructor called!" << std::endl;
	*this = cat; 
}

WrongCat &WrongCat::operator=(WrongCat const &wrongcat)
{
	std::cout << "WrongCat Assignation Operator called!" << std::endl;
	if (this == &wrongcat)
		return *this;
	this->_type = wrongcat._type;
	this->_name = wrongcat._name;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << this->_type << " WrongCat Destructor called!" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Miau'nt Miau'nt" << std::endl;
}
