/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:21:33 by tuta              #+#    #+#             */
/*   Updated: 2024/06/10 15:34:26 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argv, char **argc)
{
    Harl harl;
    int filter = -1;
    if (argv != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 0;
    }
    std::string level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
        if (argc[1] == level[i])
            filter = i;
    switch (filter)
    {
        case 0: 
			harl.complain("DEBUG");
        case 1: 
			harl.complain("INFO");
        case 2: 
			harl.complain("WARNING");
        case 3:
		{
			harl.complain("ERROR");
            break;
		}
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }   
}
