/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:10:14 by tuta              #+#    #+#             */
/*   Updated: 2024/06/10 14:33:27 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int	replace(const std::string &filename, const std::string &s1, const std::string &s2)
{
	size_t	pos;

	// Open the input file
	std::ifstream inputFile(filename);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Could not open the file " << filename << std::endl;
		return (1);
	}

	// Read the entire content of the file into a string
	std::string content((std::istreambuf_iterator<char>(inputFile)),
		std::istreambuf_iterator<char>());
	inputFile.close();

	// Perform the replacement
	pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}

	// Write the new content to the output file
	std::ofstream outputFile(filename + ".replace");
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not create the file " << filename << ".replace" << std::endl;
		return (1);
	}
	outputFile << content;
	outputFile.close();
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "Error: s1 should not be an empty string" << std::endl;
		return (1);
	}
	return (replace(filename, s1, s2));
}
