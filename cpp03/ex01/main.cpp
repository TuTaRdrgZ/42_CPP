/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:50:32 by tuta              #+#    #+#             */
/*   Updated: 2024/07/18 20:07:20 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("tuta");

	ClapTrap clapTrap2;
	ClapTrap clapTrap3("asdf");

	clapTrap.attack("enemy");
	clapTrap.takeDamage(4);
	clapTrap.beRepaired(5);

	clapTrap2.attack("enemy");
	clapTrap2.takeDamage(1);
	clapTrap2.beRepaired(5);

	clapTrap3.attack("enemy");
	clapTrap3.takeDamage(1);
	clapTrap3.beRepaired(5);

	return 0;
}
