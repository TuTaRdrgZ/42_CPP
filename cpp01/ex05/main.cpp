/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:21:33 by tuta              #+#    #+#             */
/*   Updated: 2024/06/10 15:22:44 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;
	harl.complain("ERROR");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("DEBUG");
	harl.complain("RANDOM");
	return (0);
}
