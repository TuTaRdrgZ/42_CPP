/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:25:41 by tuta              #+#    #+#             */
/*   Updated: 2024/06/10 14:03:34 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon &weapon);

	private:
		std::string _name;
		Weapon *_weapon;

};

#endif
