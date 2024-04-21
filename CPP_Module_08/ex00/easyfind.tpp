/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:14:20 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/21 23:25:08 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename Container>
void	easyfind(const Container &container, int find)
{
	std::stringstream					ss;
	typename Container::const_iterator	it;

	if (std::find(container.begin(), container.end(), find) == container.end())	
	{
		ss << find;
		throw(std::runtime_error(ss.str() + "\tnot found."));
	}
	it = std::find(container.begin(), container.end(), find);
	std::cout << find << "\tfound at index "
		<< std::distance(container.begin(), it) << ".\n";
}
