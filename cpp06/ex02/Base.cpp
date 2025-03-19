
// ╔───────────────────────────────────────────────────────¤◎¤───────────────────────────────────────────────────────╗
// 		 ✩ Destructor virtuel -> héritage avec une classe abstraite en .hpp
//       ✩ Pas besoin de constructor, automatic
//       ✩ no orthodox canonical class needed
//       ✩ 3 fonctions utilitaires demandées -> en dehors de la classe car ne modifie rien dedans
//          ✩ 2 fonctions identify -> 1 avec ptr et 1 avec ref(sans pointeur)
//          ✩ 1 fonction generate -> cree random un objet A,B,C.return un pointeur de A, B ou C -> new/delete
//       ✩ 3 classes A,B,C héritent de Base
//
//       ✩ dynamic_cast fonctionne différemment avec les références et les pointeurs
//          -pointeur: retourne nullptr si le cast échoue, sinon un pointeur valide
//          -référence: lance une exception std::bad_cast si le cast échoue-> utilisation de try/catch
//       ✩ dynamic_cast s'utilise dynamic_cast<type>(ptr/ref)
//       ✩ dynamic_cast ne fonctionne que pour les classes polymorphiques
// ╚───────────────────────────────────────────────────────¤◎¤───────────────────────────────────────────────────────╝
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

//.......................................................................................................
//								        Destructor		
//                                                                             							|
//.......................................................................................................

    Base::~Base()
    {}
//=======================================================================================================
//										   Fonctions utilitaires										|
//=======================================================================================================
// New :Création dynamique "new"-> delete dans le main
    Base	*generate(void)
    {
        // srand(time(0)); à mettre en main uniquement si plusieur appel
        int	randNbr = rand()% 3 + 1;;

        if(!(randNbr == 3))
        {
            Base	*a = new A;
            return (a);
        }
        else if(randNbr == 2)
        {
            Base	*b = new B;
            return (b);
        }
        else
        {
            Base	*c = new C;
            return (c);
        }
    }
//.......................................................................................................
//						                        Identify with pointer                                 |
//                                          							                                |
//.......................................................................................................
//------- ✩ Fonctions pour chaque objet,on lance le cast
//------- ✩ Si le cast réussit, on retourne true
//------- ✩ Si le cast échoue, on retourne false

    bool isA(Base* p) { return dynamic_cast<A*>(p) != NULL; }
    bool isB(Base* p) { return dynamic_cast<B*>(p) != NULL; }
    bool isC(Base* p) { return dynamic_cast<C*>(p) != NULL; }

   void identify(Base* p) 
   {
        bool (*casts[])(Base*)= 
        { 
            isA, 
            isB, 
            isC 
        };
        const char* types[] = { "A", "B", "C" };

        for (int i = 0; i < 3; i++) {
            if (casts[i](p))
            {
                std::cout << "This ptr is type: "<<LIGHT_GREEN<<types[i] <<RESET_COLOR<< std::endl;
                return;
            }
        }
        std::cout <<LIGHT_RED<< "Error, no match" << RESET_COLOR <<std::endl;  // Si aucun cast ne réussit
    }

//.......................................................................................................
//						                        Identify with reference                                 |
//                                          							                                |
//.......................................................................................................
//------- ✩ Fonctions de check pour chaque objet, s'il y a eu exception
//------- ✩ Tente de caster la référence d'un objet en un objet de type A, B, C
//------- ✩ Si le cast réussit, on retourne true
//------- ✩ Si le cast échoue, on retourne false

bool refToA(Base& p) 
{
    try 
    {
        (void)dynamic_cast<A&>(p);
        return true;
    }
    catch (std::bad_cast&) //ou plus général : catch (std::exception &e)
          {return false;}
}

bool refToB(Base& p) 
{
    try
    {
        (void)dynamic_cast<B&>(p);
        return true;
    } 
    catch (std::bad_cast&)
          {return false;}
}

bool refToC(Base& p) 
{
    try 
    {
        (void)dynamic_cast<C&>(p);
        return true;
    } 
    catch (std::bad_cast&) 
      {  return false;}

}

void identify(Base& p) 
{
    bool (*casts[])(Base&) = { refToA, refToB, refToC };
    const char* types[] = { "A", "B", "C" };

    for (int i = 0; i < 3; i++) {
        if (casts[i](p)) 
        {
            std::cout << "This reference is from type : "<<LIGHT_GREEN<<types[i] <<RESET_COLOR<< std::endl;
            return;
        }
    }
    std::cout << "Error: no match found" << std::endl;
}