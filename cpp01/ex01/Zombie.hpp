/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:24:39 by tuta              #+#    #+#             */
/*   Updated: 2024/06/10 12:59:24 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie{

	private:
		std::string _name;

	public:
		Zombie();
		~Zombie();
		void set_name(std::string name);
		void announce(void);
};

Zombie *zombieHorde(int N, std::string name);
