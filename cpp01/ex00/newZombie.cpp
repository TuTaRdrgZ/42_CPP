/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:45:32 by tuta              #+#    #+#             */
/*   Updated: 2024/10/30 10:56:26 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *zombie;

	try {
		zombie = new Zombie(name);
	}
	catch (std::bad_alloc &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return NULL;
	}
	return zombie;
}
