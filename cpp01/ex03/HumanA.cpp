/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:35:38 by tuta              #+#    #+#             */
/*   Updated: 2024/06/10 13:55:52 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name) , _weapon(weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
