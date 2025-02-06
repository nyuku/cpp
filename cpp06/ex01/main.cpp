
// ╔────────────────────────────────────────────────────────────¤◎¤────────────────────────────────────────────────────────────╗
// 		 ✩ ->serialization : 	convertir un objet en une séquence d'octets
//       ✩ <- deserialization : convertir une séquence d'octets en un objet
//       ✩ 
//       ✩ Créer les donnés que va contenir le pointeur
//       ✩ "struct data"       ->SERIALIZE: strucdata adresse               ----> unsigned int "serializedData"
//       ✩ "serializedData"    ->DESERIALIZE: unsigned int "serializedData" ----> new ptr
//          ---> Check if &data == &ptr
// ╚────────────────────────────────────────────────────────────¤◎¤────────────────────────────────────────────────────────────╝
#include "Serializer.hpp"
#include <iostream>

int main()
{

//.......................................................................................................
//										    Create Data 										    	|
//.......................................................................................................
    Data myData;
    myData.value = 42;
    myData.str = "Test Data";
    std::cout   << "\nAdresse de la structure myData: " 
                <<LIGHT_CYAN<< &myData <<RESET_COLOR<< std::endl;

//.......................................................................................................
//										    Serialization 												|
//.......................................................................................................

    uintptr_t serializedData;
    serializedData = Serializer::serialize(&myData);
    std::cout   << "Valeur de serializedData après serialize:  " 
                <<BLUE<< serializedData <<RESET_COLOR<< std::endl;

//.......................................................................................................
//										    Deserialization 											|
//.......................................................................................................
    
    Data *ptr;
    ptr = Serializer::deserialize(serializedData);
    std::cout   << "\nAdresse après deserialize: " 
                <<LIGHT_CYAN<< ptr <<RESET_COLOR<< std::endl;

//.......................................................................................................
//										    Check            											|
//.......................................................................................................

    if (ptr == &myData)
        std::cout <<LIGHT_GREEN<< "SUCCESS: La désérialisation a fonctionné !" <<RESET_COLOR<< std::endl;
    else
        std::cout << "ERROR: Pointeur incorrect après désérialisation !" << std::endl;

    std::cout   << "\nCheck que c'est le meme contenu:\nValeur de PTR: " 
                << ptr->value << ", Nom: " << ptr->str << std::endl
                << "Valeur myData: " << myData.value << ", Nom: " 
                << myData.str << ENDL<<ENDL;
}