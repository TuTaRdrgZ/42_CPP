/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:37:24 by bautrodr          #+#    #+#             */
/*   Updated: 2024/04/11 16:37:29 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }
    std::string mensaje;
    for (int i = 1; i < argc; i++)
    {
        mensaje += argv[i];
    }
    for (size_t i = 0; i < mensaje.size(); i++)
    {
        mensaje[i] = toupper(mensaje[i]);
    }
    std::cout << mensaje << std::endl;
    return 0;
}
