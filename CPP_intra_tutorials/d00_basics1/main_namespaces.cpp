/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_namespaces.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:08:40 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/06 13:28:49 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	gl_vr = 1;
int	f( void ) { return 2; }

namespace	Foo {

	int	gl_vr = 3;
	int	f( void ) { return 4; }

}

namespace	Bar {

	int	gl_vr = 5;
	int	f( void ) { return 6; }

}

namespace Muf = Bar; // namespace aliasing

/*
:: is a score resolution operator
*/

int	main( void ) {
	printf( "gl_var:			[%d]\n", gl_vr );
	printf( "f():			[%d]\n\n", f() );

	printf( "Foo::gl_var:	[%d]\n", Foo::gl_vr );
	printf( "Foo::f():		[%d]\n\n", Foo::f() );

	printf( "Bar::gl_var:	[%d]\n", Bar::gl_vr );
	printf( "Bar::f():		[%d]\n\n", Bar::f() );

	printf( "Muf::gl_var:	[%d]\n", Muf::gl_vr );
	printf( "Muf::f():		[%d]\n\n", Muf::f() );

	/*
	the below syntax (empty namespace and scope resolution operator) 
	is the same as the first one and is used to enhance readibility
	*/
	printf( "::gl_var:		[%d]\n", ::gl_vr );
	printf( "::f():			[%d]\n\n", ::f() );

	return 0;
}