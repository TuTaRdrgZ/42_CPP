/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:29:04 by tuta              #+#    #+#             */
/*   Updated: 2024/07/22 14:30:03 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		std::string _name;
	public:
		// Constructors
		WrongCat();
		WrongCat(std::string);
		WrongCat(WrongCat const & );
		WrongCat& operator=(WrongCat const &);
		// Destructor
		~WrongCat();
		void makeSound() const;
};

#endif
