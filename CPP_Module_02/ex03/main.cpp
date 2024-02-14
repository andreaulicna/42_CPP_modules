/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:57:32 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/14 12:20:29 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Point.class.hpp"

/**
 * @brief	This function executes a default example of checking whether a point
 * is inside a triangle. It has two such examples.
 */
void	default_example(void)
{
	Point	A(0, 0);
	Point	B(10, 30);
	Point	C(20, 0);
	Point	P1(10, 15);
	Point	P2(30, 15);

	std::cout << "Triangle: " << 
		"A = " << A << ", B = " << B << ", C = " << C << "\n";
	std::cout << "P1 " << P1 << '\n';
	std::cout << "P2 " << P2 << "\n\n";
	std::cout << "Is P1 is the triangle? " << bsp(A, B, C, P1) << '\n'; 
	std::cout << "Is P2 is the triangle? " << bsp(A, B, C, P2) << std::endl; 
}

/**
 * @brief	This function executes an interactive example of checking whether
 * a point is inside a triangle.
 * 
 * It takes command-line arguments representing the coordinates
 * of a triangle ABC and a point P. It then checks whether the point is inside
 * the triangle using the bsp function and prints the result.
 * 
 * @param	argc	number of command-line arguments
 * @param	argv	command-line arguments
 */
void interactive_example(int argc, char **argv)
{
	Point	A(std::atof(argv[1]), std::atof(argv[2]));
	Point	B(std::atof(argv[3]), std::atof(argv[4]));
	Point	C(std::atof(argv[5]), std::atof(argv[6]));
	Point	P(std::atof(argv[7]), std::atof(argv[8]));
	bool	inTriangle;

	std::cout << "Triangle: " << 
		"A = " << A << ", B = " << B << ", C = " << C << "\n";
	std::cout << "P " << P << "\n\n";
	inTriangle = bsp(A, B, C, P);
	if (inTriangle)
		std::cout << "Point P is in triangle ABC." << std::endl;
	else
		std::cout << "Point P is NOT in triangle ABC." << std::endl;
}

/**
 * @brief	This function checks whether the command-line arguments can be
 * converted to numbers.
 * 
 * It attempts to convert each argument to a double using std::strtod.
 * If the conversion is successful, meaning the entire string was
 * a valid number, end will point to the null character at the end
 * of the string and hence can be checked to validate the conversion.
 * 
 * If any argument cannot be fully converted, the function prints an error
 * message and returns false.
 * 
 * @param	argv	command-line arguments
 * @return	bool	returns true if all arguments can be converted to numbers,
 * 					false otherwise
 */
bool	checkValidNumbers(char **argv)
{
	char	*end;
	double	testConversion;

	for (int i = 1; i < 9; i++)
	{
		testConversion = std::strtod(argv[i], &end);
		if (end[0] != '\0')
		{
			std::cout << "Error: '" << argv[i] << "' is not a number.\n";
			return (false);
		}
	}
	return (true);
}

/**
 * @brief 	The main function of the program.
 * 
 * If command-line arguments are provided, it attempts to run the interactive
 * example. If not enough arguments are provided or if any argument cannot be
 * converted to a number, it prints an error message and returns EXIT_FAILURE.
 * Otherwise it runs the interactive example.
 * 
 * If no arguments are provided, it runs the default example.
 * 
 * @param	argc	number of command-line arguments
 * @param	argv	command-line arguments
 */
int main(int argc, char **argv)
{
	if (argc > 2 || argv[1])
	{
		if (argc != 9)
		{
			std::cout << "Error: "
				<< "Attempt to run interactive example unsuccessful. "
				<< "Not enough numbers provided.\n"
				<< "Example usage: ./bsp a1 a2 b1 b2 c1 c2 p1 p2" << std::endl;
			return (EXIT_FAILURE);
		}
		else if (!checkValidNumbers(argv))
			return (EXIT_FAILURE);
		else 
			interactive_example(argc, argv);
	}
	else
		default_example();
	return (EXIT_SUCCESS);
}
