
#include <fstream>
#include <iostream>


#define RESET_COLOR "\033[0m"
#define SOFT_GREEN   "\033[0;92m"
#define LIGHT_GREEN	 "\033[1;32m"
#define LIGHTPURPLE		" \033[1;35m"
#define LIGHT_LILAC		" \033[1;34m"
#define LIGHT_MAGENTA   " \033[0;95m"
#define LIGHT_CYAN		" \033[1;36m"
#define MAGENTA			" \033[0;35m"
#define LILAC			" \033[0;94m"
#define BLUE			" \033[0;34m"
#define CYAN			" \033[0;36m"
#define LIGHT_RED       " \033[0;91m"
#define GREEN           " \033[0;32m"
#define DARK_BLUE       "\033[0;94m"

void	InputPrompt(std::string& input, const std::string& promptAsk, const std::string& errorMessage);
bool	replace_str(std::string &buffer, std::string const &s1, std::string const &s2);

int main(int argc, char **argv)
{
	if (argc != 1)
	{
		std::cerr	<<LIGHT_RED<< "Error: Please execute without arguments"<<RESET_COLOR
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
	//get the files
	InputPrompt(input,"Please enter a existing file: ", "I trustes you, now please give me a file");
	fileName = input;
	input.clear();
	InputPrompt(input,"Enter the word to find:", "I trusted you, now please give me your word");
	findStr = input;
	input.clear();
	InputPrompt(input,"Enter the word to replace:", "I trusted you, now please give me an other");
	replaceStr = input;
	input.clear();
	//check the entries
	if (findStr == replaceStr)
	{
		std::cerr	<<LIGHT_RED<< "Error: you gave the two same word"<< RESET_COLOR<<std::endl;
		return (1);
	}
	std::ifstream testFile(fileName);
	if (!testFile.is_open())
	{
		std::cerr <<LIGHT_RED<< "Error: Can't open file." << RESET_COLOR<<std::endl;
		return (1);
	}
	//redirige le contenu du file dans un nouveau ficher.remplace
	std::ifstream fileRead(fileName);
	std::ofstream replaceWrite(fileName + ".replace");
	if (!replaceWrite.is_open())
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
	std::cout << LIGHT_GREEN << "All occurrences of \"" << RESET_COLOR << findStr << LIGHT_GREEN << "\" are changed into \"" << RESET_COLOR << replaceStr << LIGHT_GREEN << "\" in " << RESET_COLOR << fileName << ".replace" << std::endl;
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
		std::cerr <<LIGHT_RED<< "No occurrences of \" " <<RESET_COLOR<< s1 <<LIGHT_RED<< "\" were found to replace." <<RESET_COLOR<< std::endl;
	return(found);
}

// attend une entrée en posant une question personalisé, message d'erreur si entrée vide
void	InputPrompt(std::string& input, const std::string& promptAsk, const std::string& errorMessage)
{
	std::cout << LILAC <<promptAsk<< RESET_COLOR << std::endl;
	while (input.empty())
	{
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout <<LIGHT_RED<< errorMessage <<RESET_COLOR<< std::endl;
		}
	}
}