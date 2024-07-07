/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:58:57 by angela            #+#    #+#             */
/*   Updated: 2024/07/06 15:21:24 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout <<  "......................................................................................................................."<< std::endl;
	std::cout <<  " \t\t\t\t\t\tPolymorphisme \t\t"<< std::endl;
	std::cout <<  "......................................................................................................................."<< std::endl;
	std::cout<<LILAC<<"• This color is for Parent\n"<<std::endl;
//=======================================================================================================
//										   Animal Test											|
//=======================================================================================================

	const Animal* beast = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl<< "\n ✿-----What does the fox says? -----✿\n"<< std::endl;
	std::cout << "Animal type : " <<LIGHT_GREEN<< beast->getType() <<RESET_COLOR<<"\tgoes : ";
		beast->makeSound();
	std::cout << "Animal type : " <<LIGHT_GREEN<< dog->getType()   <<RESET_COLOR<<"\tgoes :";
		dog->makeSound();
	std::cout << "Animal type : " <<LIGHT_GREEN<< cat->getType()   <<RESET_COLOR<<"\tgoes :";
		cat->makeSound();
	std::cout << std::endl;
	
	delete cat;
	delete dog;
	delete beast;

//=======================================================================================================
//										   Wrong animal test     										|
//=======================================================================================================

	std::cout <<"\n........................................................................\n"<< std::endl;
	const WrongAnimal* wrongAnimal  = new WrongAnimal();
	const WrongAnimal* wrongCat 	= new WrongCat();
	
	std::cout << std::endl<< "\n ✿-----What wrong with these?! -----✿\n"<< std::endl;
	std::cout << "Wrong Animal Type: " <<GREEN<< wrongAnimal->getType() <<RESET_COLOR<< "\tgoes: ";
		wrongAnimal->makeSound();
	std::cout << "Wrong Animal Type: " <<GREEN<< wrongCat->getType() << RESET_COLOR<<"\tgoes: ";
		wrongCat->makeSound();
	std::cout << std::endl;

	delete wrongCat;
	delete wrongAnimal;

	return 0;
}