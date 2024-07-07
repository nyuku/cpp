#include "Dog.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
/*
copie profonde
*/

int main( void )
{
	std::cout <<  "......................................................................................................................."<< std::endl;
	std::cout <<  " \t\t\t\t\t\t🔥Je ne veux pas brûler le monde 🔥\t\t"<< std::endl;
	std::cout <<  "......................................................................................................................."<< std::endl;
	
	std::cout <<"\n............................... TEST with Brain - delete ............................... "<<std::endl;
	//allocatio memoire
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout <<std::endl;
	std::cout<<LIGHT_RED<<"--- Kill the dog ---" <<RESET_COLOR<<std::endl;
	delete dog;
	std::cout<<LIGHT_RED<<"\n--- Kill the cat---" <<RESET_COLOR<<std::endl;
	delete cat;

	std::cout <<"\n............................... TEST with TAB brain - delete ...............................\n "<<std::endl;
	std::cout<<LIGHT_RED<<"--- Release them all ---" <<RESET_COLOR<<std::endl;
	const Animal* animalsTab[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
	std::cout<<LIGHT_RED<<"--- Kill them all ---" <<RESET_COLOR<<std::endl;
	for ( int i = 0; i < 4; i++ ) //++i
	{
		delete animalsTab[i];
	}
	std::cout <<"\n............................... TEST deep copy ...............................\n "<<std::endl;
	
	std::cout<<CYAN<<"--- Toulouse wake's up ---" <<RESET_COLOR<<std::endl;
	Cat *cat_Toulouse = new Cat();
	std::cout<<CYAN<<"\n--- Berlioz purr ---" <<RESET_COLOR<<std::endl;
	Cat *cat_Berlioz = new Cat(*cat_Toulouse);// deep copy ,()

	std::cout <<CYAN<< "\nBrain status Toulouse-> idee :"<<  cat_Toulouse->getBrain()->getIdeas(0)<<" , idee 2: "<<cat_Toulouse->getBrain()->getIdeas(1)<<RESET_COLOR<< std::endl;
	std::cout <<LIGHT_LILAC<< "Brain status Berlioz-> \tidee :"<<  cat_Berlioz->getBrain()->getIdeas(0)<<" , idee 2: "<<cat_Berlioz->getBrain()->getIdeas(1) <<RESET_COLOR<< std::endl;
	

	//modifie Toulouse
	cat_Toulouse->getBrain()->setIdeas("J'ai faim", 0);
	cat_Toulouse->getBrain()->setIdeas("J'ai pas envie de faire ma lecon de gamme", 1);
	//status
	std::cout <<CYAN<< "\nBrain status Toulouse-> idee 1:"<<  cat_Toulouse->getBrain()->getIdeas(0)<<" , idee 2: "<<cat_Toulouse->getBrain()->getIdeas(1)<<RESET_COLOR<< std::endl;
	std::cout <<LIGHT_LILAC<< "Brain status Berlioz-> \tidee :"<<  cat_Berlioz->getBrain()->getIdeas(0)<<" , idee 2: "<<cat_Berlioz->getBrain()->getIdeas(1) <<RESET_COLOR<< std::endl;

	std::cout<<LIGHT_CYAN<<"\n--copy--"<<RESET_COLOR<<std::endl;
	*cat_Berlioz = *cat_Toulouse;
	std::cout <<CYAN<< "\nBrain status Toulouse-> idee :"<<  cat_Toulouse->getBrain()->getIdeas(0)<<" , idee 2: "<<cat_Toulouse->getBrain()->getIdeas(1)<<RESET_COLOR<< std::endl;
	std::cout <<LIGHT_LILAC<< "Brain status Berlioz-> \tidee :"<<  cat_Berlioz->getBrain()->getIdeas(0)<<" , idee 2: "<<cat_Berlioz->getBrain()->getIdeas(1) <<RESET_COLOR<< std::endl;

	std::cout<<LIGHT_CYAN<<"\n--Change--"<<RESET_COLOR<<std::endl;
	cat_Toulouse->getBrain()->setIdeas("Je veux vivre de mon art", 0);
	std::cout <<CYAN<< "\nBrain status Toulouse-> idee 1:"<<  cat_Toulouse->getBrain()->getIdeas(0)<<" , idee 2: "<<cat_Toulouse->getBrain()->getIdeas(1)<<RESET_COLOR<< std::endl;
	std::cout <<LIGHT_LILAC<< "Brain status Berlioz-> \tidee 1:"<<  cat_Berlioz->getBrain()->getIdeas(0)<<" , idee 2: "<<cat_Berlioz->getBrain()->getIdeas(1) <<RESET_COLOR<< std::endl;
	
	std::cout<<LIGHT_RED<<"\n------ Put them in the Schrodinger's lab ------" <<RESET_COLOR<<std::endl;
	std::cout<<LIGHT_CYAN<<"--Toulouse first--"<<RESET_COLOR<<std::endl;
	delete cat_Toulouse;
	std::cout <<LIGHT_LILAC<< "\nBrain status Berlioz-> \tidee :"<<  cat_Berlioz->getBrain()->getIdeas(0)<<" , idee 2: "<<cat_Berlioz->getBrain()->getIdeas(1) <<RESET_COLOR<< std::endl;
	std::cout<<LIGHT_CYAN<<"\n--Then Berlioz--"<<RESET_COLOR<<std::endl;
	delete cat_Berlioz;
	return 0;
}

/*
DEEP COPY:

Les deux objets (l'original et la copie) deviennent indépendants l'un de l'autre.
valgrind --leak-check=full --track-origins=yes ./my_program
*/