/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:41:52 by tuta              #+#    #+#             */
/*   Updated: 2024/11/24 13:54:50 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
	protected:
		std::string _type;
	public:
		// Constructors
		WrongAnimal();
		WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& );
		WrongAnimal& operator=(const WrongAnimal &);
		// Destructor
		virtual ~WrongAnimal();
		void makeSound() const;
		std::string getType() const;
		void setType(std::string);
};

#endif
