#include <iostream>
#include <string>
#include "Weapon.h"
#include "Player.h"

int main() {
    /* Les Armes : */
    Weapon *epee = new Weapon("Epee", "MELEE", 13);
    Weapon *baton = new Weapon("Baton", "MAGICAL", 23);
    Weapon *arc = new Weapon("Arc", "RANGED", 23);

    /* Les Joueurs et leurs méthodes : */
    Player conan= new Player("Conan", 200);
    conan.setXp(13);
    conan.setWeapon(epee);
    //conan.describe();

    Player gandalf= new Player("Gandalf", 120);
    gandalf.setXp(25);
    gandalf.setWeapon(baton);
    //gandalf.describe();

    Player noob= new Player("Noob", 0);
    noob.setXp(0);
    noob.setWeapon(arc);
    //noob.describe();

    /* Les Monstres et leurs méthodes : */
    Monster loup = new Monster("Loup", 20, 70);
    //loup.describe();
    Monster dragon = new Monster("Dragon", 100, 170);
    //dragon.describe();

    /* Les Combats : */
    gandalf.attaquer(loup);


    /*
     * Notes: certaines méthodes sont en commentaire pour ne pas qu'elles soit toutes éffectuées en même temps
     * Afin de les utiliser, Merci de retirer les symboles "//".
    */
}