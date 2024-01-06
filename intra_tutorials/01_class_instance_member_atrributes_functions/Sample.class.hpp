/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:06:15 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/06 14:24:20 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// declare new class

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

// class keyboard followed by an identifier
class Sample {

/*
the 2 lines below public keyboard allow to declare a constructor
and destructor for the class
*/
public:

    int foo; // member attribute - variable that may be used from an instance

    Sample( void );
    ~Sample( void );

    void   bar( void ); // member function - can be used in an instance of class
};

#endif