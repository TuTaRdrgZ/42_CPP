/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:51:40 by tuta              #+#    #+#             */
/*   Updated: 2024/10/30 10:55:23 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	if (N > 0)
	{
		try {
			Zombie *zombies = new Zombie[N];
			for (int i=0; i < N; i++)
				zombies[i].set_name(name); 
			return (zombies);
		}
		catch (std::bad_alloc &e) {
			std::cerr << "Error: " << e.what() << std::endl;
			return (NULL);
		}
	}
	return (NULL);
}
