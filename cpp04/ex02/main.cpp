#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();
	//const AAnimal* animal = new AAnimal()
	// main.cpp:9:30: error: allocating an object of abstract class type
    //   'AAnimal'
    //     const AAnimal* animal = new AAnimal()
    //                                 ^
	// ./AAnimal.hpp:21:15: note: unimplemented pure virtual method 'makeSound'
    //   in 'AAnimal'
    //     virtual void    makeSound() const = 0;
    //                     ^
	// 1 error generated.

	delete dog;//should not create a leak
	delete cat;

	Dog doggy; //creates an instance of the dog class.
		Dog tmp = doggy;

	const AAnimal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
	for ( int i = 0; i < 4; i++ ) {
		delete animals[i];
	}

	return 0;
}