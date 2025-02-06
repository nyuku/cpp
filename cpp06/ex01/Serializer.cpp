

// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ ->serialization : 	convertir un objet en une séquence d'octets
//       ✩ <- deserialization : convertir une séquence d'octets en un objet
//       ✩ 
//       ✩ serialize: prend un arg une structure de donnée et retourne un uintptr_t
//       ✩ 
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝
#include "Serializer.hpp"

//.......................................................................................................
//										Constructor - Destructor - copy constructor		
//                                     	    							                                |
//.......................................................................................................
    
    Serializer::Serializer(){};
    Serializer::~Serializer(){};
    Serializer::Serializer(Serializer const & src)
    {
        *this = src;
    };

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
    
    Serializer& Serializer::operator=(Serializer const & src)
    {
        if (&src != this){}
        return *this;
    }

//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================

    uintptr_t Serializer::serialize(Data* ptr)
    {
        return reinterpret_cast<uintptr_t>(ptr);
    }

    Data* Serializer::deserialize(uintptr_t raw)
    {
        return reinterpret_cast<Data*>(raw);
    }

