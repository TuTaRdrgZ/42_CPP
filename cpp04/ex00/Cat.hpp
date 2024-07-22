/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:24:24 by tuta              #+#    #+#             */
/*   Updated: 2024/07/22 13:34:24 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
#define Cat_HPP

#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
	private:
		std::string _name;
	public:
		// Constructors
		Cat();
		Cat(std::string);
		Cat(Cat const & );
		Cat& operator=(Cat const &);
		// Destructor
		~Cat();
		void makeSound() const;
};

#endif
