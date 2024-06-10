/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:52:04 by bautrodr          #+#    #+#             */
/*   Updated: 2024/06/10 12:07:12 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
	PhoneBook phoneBook;
	std::string cmd;
		std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
	while (std::getline(std::cin, cmd))
	{
        std::cout << "--------------------------------------------------" << std::endl;
		if (cmd == "ADD" || cmd == "add" || cmd == "1")
			phoneBook.add_contact();
		else if (cmd == "SEARCH" || cmd == "search" || cmd == "2")
			phoneBook.search_contact();
		else if (cmd == "EXIT" || cmd == "exit" || cmd == "3")
			return (0);
		std::cout << "--------------------------------------------------" << std::endl;
	    std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
	}
}
