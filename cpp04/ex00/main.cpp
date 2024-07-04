#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\t-----Animals-----\n" << std::endl;

	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "Dog Type : " << dog->getType() << std::endl;
	std::cout << "Cat Type : " << cat->getType() << std::endl;
	std::cout << std::endl;

	dog->makeSound();
	cat->makeSound();
	animal->makeSound();

	delete cat;
	delete dog;
	delete animal;

	std::cout << "\n\t-----WrongAnimals-----\n" << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "WrongAnimal Type : " << wrongAnimal->getType() << std::endl;
	std::cout << "WrongCat Type : " << wrongCat->getType() << std::endl;
	std::cout << std::endl;

	wrongCat->makeSound();
	wrongAnimal->makeSound();

	delete wrongCat;
	delete wrongAnimal;

	return 0;
}