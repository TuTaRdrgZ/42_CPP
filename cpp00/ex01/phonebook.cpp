/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:59:07 by bautrodr          #+#    #+#             */
/*   Updated: 2024/05/23 16:16:57 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <ostream>
#include <string>

PhoneBook::PhoneBook(void) : _counter(-1), _size(0) {}

void	PhoneBook::display_phonebook(int nb)
{
	if (nb == -1)
	{
		std::cout << "┌--------------------------------------------------┐" << std::endl;
		std::cout << '|' << std::setw(10) << "index" << " | "
				  << std::setw(10) << "first name" << " | "
				  << std::setw(10) << "last name" << " | "
				  << std::setw(10) << "nick name" << " | " << std::endl;
		std::cout << "┣--------------------------------------------------┤" << std::endl;
		for (int i=0; i < PhoneBook::_size; ++i)
			this->_contacts[i].display_all();
	}
}

void PhoneBook::add_contact(void)
{
	std::string f,l,n,p,d;

	std::cout << "first name: ";
	std::getline(std::cin, f);
	if (f.empty()) {
		std::cerr << "Invalid input" << std::endl; 
		return ;
	}
	std::cout << "last name: ";
	std::getline(std::cin, l);
	if (l.empty()) {
		std::cerr << "Invalid input" << std::endl; 
		return ;
	}
	std::cout << "nickname: ";
	std::getline(std::cin, n);
	if (n.empty()) {
		std::cerr << "Invalid input" << std::endl; 
		return ;
	}
	std::cout << "phone number: ";
	std::getline(std::cin, p);
	if (p.empty() || !Contact::isNumeric(p)) {
		std::cerr << "Invalid input" << std::endl; 
		return ;
	}
	std::cout << "darkest secret: ";
	std::getline(std::cin, d);
	if (d.empty()) {
		std::cerr << "Invalid input" << std::endl; 
		return ;
	}
	this->_size += this->_size < 8;
	this->_counter++;
	this->_counter = this->_counter % 8;
	this->_contacts[this->_counter].set_data(f, l, n, p, d, this->_counter + 1);
}

void	PhoneBook::search_contact(void)
{
	this->display_phonebook(-1);
}
