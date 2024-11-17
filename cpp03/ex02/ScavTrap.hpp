/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:57:54 by tuta              #+#    #+#             */
/*   Updated: 2024/11/17 14:41:21 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		// Constructor
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& scavtrap);
		ScavTrap& operator=(const ScavTrap& scavtrap);

		// Destructor
		~ScavTrap();

		// Override attack function
		void attack(const std::string& target);
		bool canAttack() const;

		// New member function
		void guardGate();
};

#endif
