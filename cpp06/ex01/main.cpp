
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
    myData.name = "Test Data";
    std::cout<<LIGHT_MAGENTA<< "▶ Creation de la structure myData:"<< RESET_COLOR<<" value:" <<myData.value <<RESET_COLOR<< ", name: " << myData.name << std::endl;
    std::cout   << "Adresse de la structure myData: " 
                <<LIGHT_CYAN<< &myData <<RESET_COLOR<< std::endl;

//.......................................................................................................
//										    Serialization 												|
//.......................................................................................................

    uintptr_t serializedData;
    std::cout<<LIGHT_MAGENTA<< "\n▶ Création du pointeur contenant la Serialization de myData:"<<RESET_COLOR<< std::endl;
    serializedData = Serializer::serialize(&myData);
    std::cout   << "Valeur de 'serializedData':  " 
                <<BLUE<< serializedData <<RESET_COLOR<< std::endl;

//.......................................................................................................
//										    Deserialization 											|
//.......................................................................................................
    
    Data *ptr;
    ptr = Serializer::deserialize(serializedData);
    std::cout<<LIGHT_MAGENTA<< "\n▶  Deserialization de 'serializedData':"<<RESET_COLOR<< std::endl;
    std::cout   << "Adresse après deserialize: " 
                <<LIGHT_CYAN<< ptr <<RESET_COLOR<< std::endl;

//.......................................................................................................
//										    Check            											|
//.......................................................................................................

    if (ptr == &myData)
        std::cout <<LIGHT_GREEN<< "\nSUCCESS: La désérialisation a fonctionné !" <<RESET_COLOR<< std::endl;
    else
        std::cout << "ERROR: Pointeur incorrect après désérialisation !" << std::endl;

    std::cout   << "\n▶ Check que c'est le meme contenu:\nValeur de PTR: " 
                << ptr->value << ", Nom: " << ptr->name << std::endl
                << "Valeur myData: " << myData.value << ", Nom: " 
                << myData.name << ENDL<<ENDL;
}