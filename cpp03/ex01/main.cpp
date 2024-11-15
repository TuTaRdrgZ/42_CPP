/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:50:32 by tuta              #+#    #+#             */
/*   Updated: 2024/11/15 12:27:41 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ClapTrap claptrap("clap-trap");
    
    claptrap.attack("target1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    ScavTrap scavtrap("scav-trap");

    scavtrap.attack("target2");
    scavtrap.takeDamage(30);
    scavtrap.beRepaired(15);
    scavtrap.guardGate();

    return 0;
}
