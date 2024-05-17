/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:06:38 by angela            #+#    #+#             */
/*   Updated: 2024/05/16 20:03:09 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fstream>
#include <iostream>


#define RESET_COLOR		"\033[0m"
#define GREEN			"\033[0;92m"
#define LIGHT_GREEN		"\033[1;32m"
#define LIGHTPURPLE		"\033[1;35m"
#define LIGHT_LILAC		"\033[1;34m"
#define LIGHT_MAGENTA	"\033[0;95m"
#define LIGHT_CYAN		"\033[1;36m"
#define MAGENTA			"\033[0;35m"
#define LILAC			"\033[0;94m"
#define BLUE			"\033[0;34m"
#define LIGHG_PURPLE	"\033[0;36m"
#define LIGHT_RED		"\033[0;91m"
#define SOFT_GREEN		"\033[0;32m"
#define DARK_BLUE		"\033[0;94m"
#define PEACH			"\033[0;93m"
//-----------------------------------------------------------------------------//

void	InputPrompt(std::string& input, const std::string& promptAsk, const std::string& errorMessage,  const std::string& color);
bool	replace_str(std::string &buffer, std::string const &s1, std::string const &s2);
bool	isFileEmpty(std::ifstream &file);

int main(int argc, char **argv)
{
	if (argc != 1)
	{
		std::cerr	<<LIGHT_RED<< std::endl<< "Error: Please execute without arguments"<<RESET_COLOR
					 << std::endl;
		return (1);
	}
	(void) argv;
	std::string buffer;
	std::string line;
	std::string fileName;
	std::string input;
	std::string findStr;
	std::string replaceStr;

	//--------PARSING---------//
	
	InputPrompt(input,"Please enter a existing file: ", "I trustes you, now please give me a file", LILAC);
	fileName = input;
	input.clear();
	std::ifstream testFile(fileName);
	while ((!testFile.is_open() || isFileEmpty(testFile)) && !std::cin.eof())
	{
        if (!testFile.is_open())
			std::cerr << LIGHT_RED << "Error: Can't open file." << RESET_COLOR << std::endl;
		else if (isFileEmpty(testFile))
		{
            std::cerr << LIGHT_RED << "Error: The file is empty. Please enter a non-empty file." << RESET_COLOR << std::endl;
            testFile.close(); // Close the file to allow reopening
        }
        InputPrompt(input, "Please enter an existing file: ", "I trust you, now please give me a file", LILAC);
        fileName = input;
        input.clear();
        testFile.open(fileName);
		
    }
	
	InputPrompt(input,"Enter the word to find:", "I trusted you, now please give me your word", LIGHT_CYAN);
	findStr = input;
	input.clear();
	InputPrompt(input,"Enter the word to replace:", "I trusted you, now please give me an other", LILAC);
	replaceStr = input;
	input.clear();
	
	//--------check the entries--------------
	while (findStr == replaceStr && (!std::cin.eof()))
	{
		std::cerr<<LIGHT_RED<< "Error: you gave the two same word, try a another word"<< RESET_COLOR<<std::endl;
		InputPrompt(input,"Enter the word to replace:", "I trusted you, now please give me an other", LILAC);
		replaceStr = input;
		input.clear();
	}

	//redirige le contenu du file dans un nouveau ficher.remplace
	std::ifstream fileRead(fileName);
	std::ofstream replaceWrite(fileName + ".replace");
	if (!replaceWrite.is_open() && (!std::cin.eof()))
	{
		std::cerr <<LIGHT_RED<< "Error : Can't generate the replacement file: " <<RESET_COLOR<< fileName + ".replace" << std::endl;
		return (1);
	}

	if (fileRead.is_open())
	{
		buffer.clear();
		while (true)
		{
			std::getline(fileRead, line);
			buffer += line;
			if (fileRead.eof())
				break;
			buffer += '\n'; // necessaire car getline ne le fait pas
		}
		if (!replace_str(buffer, findStr, replaceStr))
			return (1);
		replaceWrite << buffer;
		fileRead.close();
		replaceWrite.close();
	}
	if (!std::cin.eof())
		std::cout << LIGHT_GREEN << "All occurrences of \"" << RESET_COLOR << findStr << LIGHT_GREEN << "\" are changed into \"" << RESET_COLOR << replaceStr << LIGHT_GREEN << "\" in " << RESET_COLOR << fileName << ".replace" << std::endl;
	testFile.close();
	return 0;
}

bool replace_str(std::string &buffer, std::string const &s1, std::string const &s2)
{
	size_t i = 0;
	bool found = false;
	while (true)
	{
		i = buffer.find(s1, i);
		if (i == std::string::npos)
			break;

		buffer.erase(i, s1.length());
		buffer.insert(i, s2);
		i += s2.length();
		found = true;
	}
	if (found == false)
		std::cerr <<LIGHT_RED<< "No occurrences of \" " <<RESET_COLOR<< s1 <<LIGHT_RED<< "\" were found to replace." <<RESET_COLOR<< std::endl<< std::endl;
	return(found);
}

void InputPrompt(std::string& input, const std::string& promptAsk, const std::string& errorMessage, const std::string& color)
{
    if (!std::cin.eof())
        std::cout<< std::endl << color << promptAsk << RESET_COLOR << std::endl;
    while (input.empty() && !std::cin.eof())
	{
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cerr << LIGHT_RED << std::endl << "Error: You entered: [ CTRL + D ]" << RESET_COLOR << std::endl;
            std::cin.clear();
            exit(1);
        }
        if (input.empty() && !std::cin.eof()) {
            std::cout << LIGHT_RED << errorMessage << RESET_COLOR << std::endl;
        }
    }
}

bool	isFileEmpty(std::ifstream &file) 
{
    return file.peek() == std::ifstream::traits_type::eof();
}