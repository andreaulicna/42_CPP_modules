/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:14:20 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/21 16:49:08 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename Container>
void	easyfind(const Container &container, int find)
{
	std::stringstream	ss;

	if (std::find(container.begin(), container.end(), find) == container.end())	
	{
		ss << find;
		throw(std::runtime_error(ss.str() + "\tnot found."));
	}
	else
		std::cout << find << "\tfound at index " << std::distance(container.begin(), std::find(container.begin(), container.end(), find)) << "." << std::endl;
}
