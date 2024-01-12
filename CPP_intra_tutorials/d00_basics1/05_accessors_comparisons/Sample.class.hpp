/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:07:11 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/07 12:34:34 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class	Sample
{
public:
	Sample(void);
	~Sample(void);

	int		getFoo(void) const;
	void	setFoo(int v);

	int		compare(Sample *other) const;

private:
	int		_foo;
};

#endif