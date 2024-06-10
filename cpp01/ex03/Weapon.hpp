/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:16:01 by tuta              #+#    #+#             */
/*   Updated: 2024/06/10 14:03:40 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string getType();
		void		setType(std::string type);
		
	private:
		std::string _type;
};

#endif
