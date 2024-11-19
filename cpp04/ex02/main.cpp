/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:47:33 by tuta              #+#    #+#             */
/*   Updated: 2024/11/19 22:18:14 by tuta             ###   ########.fr       */
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

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout << "Wrong : " << wrongcat->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	// meta->makeSound();
	std::cout << "Wrong : ";
	wrongcat->makeSound();

	// delete meta;
	delete j;
	delete i;
	delete wrongcat;

	return 0;
}
