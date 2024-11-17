/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:50:32 by tuta              #+#    #+#             */
/*   Updated: 2024/11/17 14:43:00 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	ClapTrap ct1("Clap-Trap");
	FragTrap ct2("Frag-Trap");

	ct1.setAttackDamage(15);
	ct2.beRepaired(5);
	ct1.attack(ct2.getName());
	ct2.takeDamage(ct1.getAttackDamage());
	ct2.highFivesGuys();
	return 0;
}
