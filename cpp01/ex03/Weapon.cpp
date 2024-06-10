/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:31:52 by tuta              #+#    #+#             */
/*   Updated: 2024/06/10 13:44:47 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon()
{
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

const std::string Weapon::getType()
{
	return (this->_type);
}
