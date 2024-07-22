/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:23:48 by tuta              #+#    #+#             */
/*   Updated: 2024/07/22 15:26:51 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain();
		Brain(std::string idea);
		Brain(const Brain &);
		Brain &operator=(const Brain &);
		~Brain();
};

#endif
