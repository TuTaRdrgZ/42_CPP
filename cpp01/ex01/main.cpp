/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:33:47 by tuta              #+#    #+#             */
/*   Updated: 2024/10/30 10:54:51 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int	N = 1000000000;

	Zombie *zombie = zombieHorde(N, "asdf");
	if (zombie == NULL)
		return (1);
	for (int i = 0; i < N; i++)
		zombie[i].announce();
	delete [] zombie;
	Zombie *newZombie = zombieHorde(1, "TuTa");
	if (newZombie == NULL)
		return (1);
	newZombie[0].announce();
	delete [] newZombie;
	return (0);
}
