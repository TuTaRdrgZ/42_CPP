/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:21:55 by tuta              #+#    #+#             */
/*   Updated: 2024/11/19 21:21:34 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		// Constructors
		Dog();
		Dog(Dog const &);
		Dog& operator=(Dog const&);
		// Destructor
		~Dog();
		void makeSound() const;
};

#endif
