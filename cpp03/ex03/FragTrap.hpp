/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:32:13 by tuta              #+#    #+#             */
/*   Updated: 2024/11/15 12:44:34 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		// Constructor
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap& fragtrap);
		FragTrap& operator=(const FragTrap& fragtrap);

		// Destructor
		~FragTrap();

		void highFivesGuys(void);
		void attack(const std::string& target);
		bool canAttack(FragTrap fragtrap);
};

#endif
