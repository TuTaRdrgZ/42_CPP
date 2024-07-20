/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:57:54 by tuta              #+#    #+#             */
/*   Updated: 2024/07/20 13:25:11 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		// Constructor
		ScavTrap(const std::string& name);

		// Destructor
		~ScavTrap();

		// Override attack function
		void attack(const std::string& target);
		bool canAttack(ScavTrap scavtrap);

		// New member function
		void guardGate();
};

#endif
