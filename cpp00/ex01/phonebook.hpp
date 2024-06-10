/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:59:07 by bautrodr          #+#    #+#             */
/*   Updated: 2024/06/10 12:06:51 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#   define PHONEBOOK_HPP
#   include "contact.hpp"
#   include <iostream>
#   include <iomanip>

class PhoneBook
{
    private:
        Contact _contacts[8];
        int _counter;
        int _size;

    public:
        PhoneBook(void);
        void display_phonebook(int index);
        void add_contact(void);
        void search_contact(void);
};
#endif
