
// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ ->serialization : 	convertir un objet en une séquence d'octets
//       ✩ <- deserialization : convertir une séquence d'octets en un objet
//       ✩ 
//       ✩ Créer les donnés que va contenir le pointeur
//       ✩ 
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝
#include "Serializer.hpp"

int main()
{
    Data myData;
    myData.value = 42;
    myData.str = "Test Data";

    std::cout << "Adresse de myData: " << &myData << std::endl;

    uintptr_t raw;

    //Serialization, modifie le pointeur existant contenant nos données par constructeur copy
    raw = Serializer::serialize(&myData);
    std::cout << "Valeur de raw après serialize: " << raw << std::endl;

    //Deserialization
    Data *ptr;
    ptr = Serializer::deserialize(raw);
    std::cout << "Adresse après deserialize: " << ptr << std::endl;

    if (ptr == &myData)
        std::cout << "SUCCESS: La désérialisation a fonctionné !" << std::endl;
    else
        std::cout << "ERROR: Pointeur incorrect après désérialisation !" << std::endl;

    std::cout << "Valeur de PTR: " << ptr->value << ", Nom: " << ptr->str << std::endl;
    std::cout << "Valeur myData: " << myData.value << ", Nom: " << myData.str << std::endl;
    

}