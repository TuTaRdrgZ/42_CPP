/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:10:26 by tuta              #+#    #+#             */
/*   Updated: 2024/06/10 15:21:24 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	this->func[0] = &Harl::debug;
	this->func[1] = &Harl::info;
	this->func[2] = &Harl::warning;
	this->func[3] = &Harl::error;
	
	this->messages[0] = "DEBUG";
	this->messages[1] = "INFO";
	this->messages[2] = "WARNING";
	this->messages[3] = "ERROR";
}

Harl::~Harl() {}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string message)
{
	for (int i = 0; i < 4; i++)
		if (this->messages[i] == message)
		{
			(this->*func[i])();
			break;
		}
}
