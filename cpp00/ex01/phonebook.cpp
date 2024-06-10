/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:59:07 by bautrodr          #+#    #+#             */
/*   Updated: 2024/06/10 12:06:20 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>

PhoneBook::PhoneBook(void) : _counter(-1), _size(0) {}

void	PhoneBook::display_phonebook(int nb)
{
	if (nb == -1)
	{
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << '|' << std::setw(10) << "index" << "|"
				  << std::setw(10) << "first name" << "|"
				  << std::setw(10) << "last name" << "|"
				  << std::setw(10) << "nick name" << "|" << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
		for (int i=0; i < PhoneBook::_size; ++i)
			this->_contacts[i].display_all();
	}
    else
        this->_contacts[nb].display_details();
}

void PhoneBook::add_contact(void)
{
	std::string f,l,n,p,d;

	std::cout << "first name: ";
	std::getline(std::cin, f);
    while (f.empty())
    {
	    std::cout << "first name: ";
	    std::getline(std::cin, f);
    }
	std::cout << "last name: ";
	std::getline(std::cin, l);
	while (l.empty())
    {
        std::cout << "last name: ";
        std::getline(std::cin, l);
	}
	std::cout << "nickname: ";
	std::getline(std::cin, n);
	while (n.empty()) {
        std::cout << "nickname: ";
        std::getline(std::cin, n);
	}
	std::cout << "phone number: ";
	std::getline(std::cin, p);
	while (p.empty() || !Contact::isNumeric(p)) {
        std::cout << "phone number: ";
        std::getline(std::cin, p);
	}
	std::cout << "darkest secret: ";
	std::getline(std::cin, d);
	while (d.empty()) {
        std::cout << "darkest secret: ";
        std::getline(std::cin, d);
	}
	this->_size += this->_size < 8;
	this->_counter++;
	this->_counter = this->_counter % 8;
	this->_contacts[this->_counter].set_data(f, l, n, p, d, this->_counter + 1);
}

void	PhoneBook::search_contact(void)
{
	this->display_phonebook(-1);
    std::string number;
    std::cout << "Select a contact: ";
    std::getline(std::cin, number, '\n');
    while (number.empty() || !Contact::isNumeric(number))
    {
	    this->display_phonebook(-1);
        std::cout << "Select a contact: ";
        std::getline(std::cin, number, '\n');
        std::cout << "--------------------------------------------------" << std::endl;
    }
    if (number.size() == 1 && number[0] >= '1' && number[0] <= '8' && (number[0] - 49) < this->_size)
        this->display_phonebook((number[0] - 49));
}
