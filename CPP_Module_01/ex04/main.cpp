/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:43:30 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/15 19:30:23 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file	main.cpp
 * @brief	A program to replace occurrences of a string in a file with another
 * string.
 *
 * This program takes three parameters: a filename and two strings, s1 and s2.
 * It opens the file specified by the filename, reads its contents, and replaces
 * every occurrence of s1 with s2. The modified content is then written
 * to a new file named <filename>.replace.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

/**
 * @function	wrongParameters
 * @brief	Handles the wrong numberof parameters provided.
 * @return 	int 	returns 1 to indicate an error.
 */
int	wrongParameters(void)
{
	std::cout << "Error: Wrong number of parameters provided.\n"
		<< "Correct usage: ./sed filename s1 s2" << std::endl;
	return (1);
}

/**
 * @function	errorOpenFile
 * @brief	Prints an error message and returns 1 when a file fails to open.
 * @param	name	name of the file that failed to open
 * @return	int		returns 1 to indicate an error
 */
int	errorOpenFile(std::string name)
{
	std::cout << "Error: "<< name << " file open error." << std::endl;
	return (1);
}

/**
 * @function	copyContentIntoReplace
 * @brief	Copies the content of the original file into a new file,
 * replacing occurrences of s1 with s2.
 * @param	ofs				ofstream object for the new file
 * @param	originalContent	content of the original file
 * @param	s1				string to be replaced
 * @param	s2				string to replace s1
 * @return	int				returns 0 on success, 1 on failure
 */
int	copyContentIntoReplace(std::ofstream &ofs, std::string originalContent,
	std::string s1, std::string s2)
{
	std::size_t			i;
	std::size_t			move_to;	

	i = 0;
	while (true)
	{
		move_to = originalContent.find(s1, i);
		if (move_to != std::string::npos)
		{
			ofs << originalContent.substr(i, move_to - i);
			ofs << s2;
			i = move_to + s1.length();
		}
		else
		{
			ofs << originalContent.substr(i, std::string::npos);
			break ;
		}
	}
	return(0);
}

int	main(int argc, char **argv)
{
	std::ifstream		ifs;
	std::ofstream		ofs;
	std::stringstream	buff;
	std::string			originalContent;

	if (argc < 4)
		return (wrongParameters());
		
	ifs.open(argv[1]);
	if (!ifs.is_open())
		return (errorOpenFile("Input"));
	buff << ifs.rdbuf();
	ifs.close();
	originalContent = buff.str();
	ofs.open((std::string(argv[1]) + ".replace").c_str());
	if (!ofs.is_open())
		return (errorOpenFile("Output"));
	if (strlen(argv[2]) == 0)
		ofs << originalContent;
	else
		copyContentIntoReplace(ofs, originalContent, argv[2], argv[3]);
	ofs.close();
	return (0);
}
