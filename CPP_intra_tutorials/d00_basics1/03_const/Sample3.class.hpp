/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample3.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:45:26 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/06 17:17:11 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE3_CLASS_H
# define SAMPLE3_CLASS_H

class Sample3
{
public:
	float const	pi;
	int			qd;

	Sample3(float const f);
	~Sample3(void);

	void	bar(void) const;
};

#endif