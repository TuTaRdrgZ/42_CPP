/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:32:13 by tuta              #+#    #+#             */
/*   Updated: 2024/11/15 13:05:58 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
	private:
		std::string _name;
	public:
		// Constructor
		DiamondTrap();
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap& diamondtrap);
		DiamondTrap& operator=(const DiamondTrap& diamondtrap);

		// Destructor
		~DiamondTrap();

		void highFivesGuys(void);
		bool canAttack(DiamondTrap diamondtrap);
		void whoAmI();
		using ScavTrap::attack;
};

#endif
