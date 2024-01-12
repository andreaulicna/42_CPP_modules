/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:15:26 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/06 17:20:41 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

/*
Public and private keywords allow to control the encapsulation of the member
of a class.
*/
class Sample
{
public:
    int		publicFoo;

    Sample(void);
    ~Sample(void);

	void	publicBar(void) const;

private:
    int		_privateFoo;

	void	_privateBar(void) const;
};

#endif