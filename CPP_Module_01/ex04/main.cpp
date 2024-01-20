/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:43:30 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/20 13:07:19 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void	extractStringFromLine(std::string line, std::ofstream &ofs,
	std::string s1, std::string s2)
{
	std::stringstream	ss;
	std::string			str;
	
	ss.str(line); // Set the new content
	while (std::getline(ss, str, ' '))
	{
		if (str == s1)
			ofs << s2 << ' ';
		else
			ofs << str << ' ';
	}
	ss.clear(); // Clear any error flags
	ss.str(""); // Clear the content
}

int	wrongParameters(void)
{
	std::cout << "Error: Wrong number of parameters provided.\n"
		<< "Correct usage: ./sed filename s1 s2" << std::endl;
	return (1);
}

int	errorOpenFile(std::string name)
{
	std::cout << "Error: "<< name << " file open error." << std::endl;
	return (1);
}

int	main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		line;

	if (argc < 4)
		return (wrongParameters());
	ifs.open(argv[1]);
	if (!ifs.is_open())
		return (errorOpenFile("Input"));
	ofs.open(std::string(argv[1]) + ".replace");
	if (!ofs.is_open())
	{
		ifs.close();
		return (errorOpenFile("Output"));
	}
	if (std::getline(ifs, line))
		extractStringFromLine(line, ofs, argv[2], argv[3]);
	while (std::getline(ifs, line))
	{
		ofs << '\n';
		extractStringFromLine(line, ofs, argv[2], argv[3]);
	}
	ifs.close();
	ofs.close();
	return (0);
}
