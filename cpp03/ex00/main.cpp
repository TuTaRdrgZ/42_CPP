/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:50:32 by tuta              #+#    #+#             */
/*   Updated: 2024/07/17 18:12:10 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("ClapTrap");

	std::cout << clapTrap.getName() << std::endl;
	ClapTrap clapTrap2(clapTrap);
	ClapTrap clapTrap3 = clapTrap;

	clapTrap.attack("enemy");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(5);

	clapTrap2.attack("enemy");
	clapTrap2.takeDamage(10);
	clapTrap2.beRepaired(5);

	clapTrap3.attack("enemy");
	clapTrap3.takeDamage(10);
	clapTrap3.beRepaired(5);

	return 0;
}
