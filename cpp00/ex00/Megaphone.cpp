/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:00:35 by angela            #+#    #+#             */
/*   Updated: 2024/03/11 15:02:04 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int words = 1;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while (words < argc)
        {
            int j = 0;
			int end = 0;
			while (argv[words][end])
				end++;
            while (argv[words][j])
            {
                if ((j == 0 && argv[words][j] == ' ') || ( j == end && argv[words][end] == ' ' ))
					j++;
				std::cout << (char) std::toupper(argv[words][j]);
                j++;
            }
			if (words < (argc-1))
				std::cout <<" ";
            words++;
        }
    }
    std::cout << std::endl;
	return (0);
}