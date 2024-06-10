/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:33:47 by tuta              #+#    #+#             */
/*   Updated: 2024/06/10 13:03:37 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int	N = 5;

	Zombie *zombie = zombieHorde(N, "asdf");
	for (int i = 0; i < N; i++)
		zombie[i].announce();
	delete [] zombie;
	Zombie *newZombie = zombieHorde(1, "TuTa");
	newZombie[0].announce();
	delete [] newZombie;
	return (0);
}
