#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main() {
    // Test de la fonction generate
    std::cout << "==== Test generate() ====" << std::endl;
    Base* obj = generate();  // Crée un objet A, B ou C aléatoirement

    // Identification avec pointeur
    std::cout << "==== Test identify(Base* p) ====" << std::endl;
    identify(obj);  // Identifie l'objet via un pointeur

    // Identification avec référence
    std::cout << "==== Test identify(Base& p) ====" << std::endl;
    identify(*obj);  // Identifie l'objet via une référence

    // Nettoyage de la mémoire
    delete obj;  // Libère la mémoire allouée dynamiquement

    // Test avec un objet statique (créé directement)
    std::cout << "==== Test avec un objet statique ====" << std::endl;
    A a;  // Création d'un objet A
    identify(a);  // Identifie l'objet A via référence

    B b;  // Création d'un objet B
    identify(b);  // Identifie l'objet B via référence

    C c;  // Création d'un objet C
    identify(c);  // Identifie l'objet C via référence

    return 0;
}
