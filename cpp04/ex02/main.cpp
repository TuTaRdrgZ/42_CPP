/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:47:33 by tuta              #+#    #+#             */
/*   Updated: 2024/08/05 12:07:09 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	// const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrongcat = new WrongCat();

	std::cout << std::endl << "Getting types from animal pointer(s)" << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout << "Wrong : " << wrongcat->getType() << " " << std::endl;
	std::cout << std::endl << "Getting Sounds from animal pointer(s)" << std::endl;
	i->makeSound();
	j->makeSound();
	// meta->makeSound();
	std::cout << "Wrong : ";
	wrongcat->makeSound();

	// delete meta;
	delete j;
	delete i;
	delete wrongcat;

	// ----- ex01 ----- //
	
	// const Animal* animals[4];
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (i % 2 == 0)
	// 		animals[i] = new Dog();
	// 	else
	// 		animals[i] = new Cat();
	// }
	// for (int i = 0; i < 4; i++)
	// {
	// 	delete animals[i];
	// }

	return 0;
}
