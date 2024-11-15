/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:50:32 by tuta              #+#    #+#             */
/*   Updated: 2024/11/15 13:12:59 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	ClapTrap ct1("Clap-Trap");
	FragTrap ct2("Frag-Trap");
	DiamondTrap ct3("tuta");

	ct1.setAttackDamage(15);
	ct2.beRepaired(5);
	ct1.attack(ct2.getName());
	ct2.takeDamage(ct1.getAttackDamage());
	ct2.highFivesGuys();
	ct3.setAttackDamage(20);
	ct3.attack(ct2.getName());
	ct3.whoAmI();
}
