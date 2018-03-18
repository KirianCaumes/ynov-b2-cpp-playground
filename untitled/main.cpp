#include <iostream>

int main() {
    std::cout << "C'est pas facile a faire fonctionner" << std::endl;

    float probaBlueScreen = 0.1;
    float nbrJour = 365;
    std::cout << "La probabilite de faire une blue screen est de :" << nbrJour*probaBlueScreen << std::endl;

    int monTest = 53;
    std::cout << "La valeur en memoire est de :" << &monTest << std::endl;

    const char * foo = "hello";
    std::cout << "La valeur en memoire est de :" << *(foo+4) << std::endl;
    std::cout << "Le charactere est :" <<  foo[4] << std::endl;
    foo[4];

    return 0;
}