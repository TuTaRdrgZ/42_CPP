/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:57:01 by bautrodr          #+#    #+#             */
/*   Updated: 2024/05/22 12:52:35 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "contact.hpp"

bool Contact::isNumeric(const std::string& str)
{
    if (str.empty()) {
        return false;
    }
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

void	Contact::display_all()
{
	std::cout << this->_first_name << std::endl;
	std::cout << this->_last_name << std::endl;
	std::cout << this->_nickname << std::endl;
	std::cout << this->_phonenumber << std::endl;
}

void Contact::set_data(std::string f, std::string l, std::string n, std::string p, std::string d, int i)
{
	this->_first_name = f;
	this->_last_name = l;
	this->_nickname = n;
	this->_phonenumber = p;
	this->_darkest_secret = d;
	this->_index = i;
}

void Contact::display_details(void)
{
	std::cout << "First name: " << this->_first_name << std::endl;
	std::cout << "Last name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phonenumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}
