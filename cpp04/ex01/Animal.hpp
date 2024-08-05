/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:15:25 by tuta              #+#    #+#             */
/*   Updated: 2024/08/05 12:03:30 by tuta             ###   ########.fr       */
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
	private:
		std::string _name;
	public:
		// Constructors
		Animal();
		Animal(const std::string type);
		Animal(const Animal& );
		Animal& operator=(const Animal &);
		// Destructor
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;
		void setType(std::string);
		std::string getName() const;
		void setName(std::string);
};

#endif
