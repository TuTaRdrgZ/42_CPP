/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:15:25 by tuta              #+#    #+#             */
/*   Updated: 2024/11/24 13:37:35 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <cstdlib>

class Animal
{
	protected:
		std::string _type;
	public:
		// Constructors
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& );
		Animal& operator=(const Animal &);
		// Destructor
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;
		void setType(std::string);
};

#endif
