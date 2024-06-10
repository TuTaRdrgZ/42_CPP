/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:00:46 by tuta              #+#    #+#             */
/*   Updated: 2024/06/10 15:21:00 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
#include <iostream>

class Harl
{
	public:
		Harl();
		~Harl();
		void complain(std::string level);

	private:
		void	(Harl::*func[4])(void);
		std::string messages[4];
		void	debug(void);
		void 	info(void);
		void	warning(void);
		void	error(void);
};

#endif
