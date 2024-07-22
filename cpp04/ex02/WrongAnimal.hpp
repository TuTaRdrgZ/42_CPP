/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:41:52 by tuta              #+#    #+#             */
/*   Updated: 2024/07/22 15:00:16 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
	protected:
		std::string _type;
	private:
		std::string _name;
	public:
		// Constructors
		WrongAnimal();
		WrongAnimal(const std::string type);
		WrongAnimal(const WrongAnimal& );
		WrongAnimal& operator=(const WrongAnimal &);
		// Destructor
		virtual ~WrongAnimal();
		virtual void makeSound() const;
		std::string getType() const;
		void setType(std::string);
		std::string getName() const;
		void setName(std::string);
};

#endif
