/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:47:33 by tuta              #+#    #+#             */
/*   Updated: 2024/11/19 21:31:06 by tuta             ###   ########.fr       */
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
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "Type of j: " << j->getType() << std::endl;
    std::cout << "Type of i: " << i->getType() << std::endl;

    std::cout << "Calling makeSound() on i (Cat): ";
    i->makeSound();

    std::cout << "Calling makeSound() on j (Dog): ";
    j->makeSound();

    std::cout << "Calling makeSound() on meta (Animal): ";
    meta->makeSound();

    std::cout << "\nAdditional Tests:\n";

    const Animal* k = new Dog();
    const Animal* l = new Cat();

    std::cout << "Type of k: " << k->getType() << std::endl;
    std::cout << "Type of l: " << l->getType() << std::endl;

    std::cout << "Calling makeSound() on k (Dog): ";
    k->makeSound();

    std::cout << "Calling makeSound() on l (Cat): ";
    l->makeSound();

    std::cout << "\nWrong Animal Tests:\n";

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();
    const WrongCat* wrongCat = new WrongCat();

    std::cout << "Type of wrongCat: " << wrongCat->getType() << std::endl;
    std::cout << "Calling makeSound() on wrongCat: ";
    wrongCat->makeSound();

    std::cout << "Type of wrongI: " << wrongI->getType() << std::endl;
    std::cout << "Calling makeSound() on wrongI (WrongCat): ";
    wrongI->makeSound();

    std::cout << "Type of wrongMeta: " << wrongMeta->getType() << std::endl;
    std::cout << "Calling makeSound() on wrongMeta (WrongAnimal): ";
    wrongMeta->makeSound();

    delete meta;
    delete j;
    delete i;
    delete k;
    delete l;
    delete wrongMeta;
    delete wrongI;
    delete wrongCat;
	return 0;
}
