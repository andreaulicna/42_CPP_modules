/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 23:47:25 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/31 18:02:48 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CLASS_HPP
# define HARL_CLASS_CPP

# include <iostream>

class Harl
{
public:
	Harl(void);
	~Harl(void);

	void	complain(std::string level) const;
	
private:
	void	_debug(void) const;
	void	_info(void) const;
	void	_warning(void) const;
	void	_error(void) const;
};

#endif