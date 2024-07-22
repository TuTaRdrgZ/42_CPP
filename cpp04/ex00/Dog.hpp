/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:21:55 by tuta              #+#    #+#             */
/*   Updated: 2024/07/22 13:34:56 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"

class Dog : public Animal
{
	private:
		std::string _name;
	public:
		// Constructors
		Dog();
		Dog(std::string);
		Dog(Dog const &);
		Dog& operator=(Dog const&);
		// Destructor
		~Dog();
		void makeSound() const;
};

#endif
