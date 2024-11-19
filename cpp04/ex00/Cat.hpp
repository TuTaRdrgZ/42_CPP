/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:24:24 by tuta              #+#    #+#             */
/*   Updated: 2024/11/19 21:21:42 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		// Constructors
		Cat();
		Cat(Cat const & );
		Cat& operator=(Cat const &);
		// Destructor
		~Cat();
		void makeSound() const;
};

#endif
