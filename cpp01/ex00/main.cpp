/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:33:47 by tuta              #+#    #+#             */
/*   Updated: 2024/10/29 11:40:06 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int main(void)
{
	Zombie *zombie = newZombie("Heap bro");
	zombie->announce();
	randomChump("Stack bro");
	delete(zombie);
	return 0;
}
