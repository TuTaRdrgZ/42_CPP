/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:50:32 by tuta              #+#    #+#             */
/*   Updated: 2024/07/20 13:30:39 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    // Crear una instancia de ClapTrap
    ClapTrap claptrap("clap-trap");
    
    // Llamar a los métodos de ClapTrap
    claptrap.attack("target1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    // Crear una instancia de ScavTrap
    ScavTrap scavtrap("scav-trap");

    // Llamar a los métodos de ScavTrap
    scavtrap.attack("target2");
    scavtrap.takeDamage(30);
    scavtrap.beRepaired(15);
    scavtrap.guardGate();

    return 0;
}
