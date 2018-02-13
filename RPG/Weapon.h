//
// Created by Kirian on 13/02/2018.
//
#include <string>
#include "WeaponType.h"

using namespace std;

#ifndef RPG_WEAPON_H
#define RPG_WEAPON_H


class Weapon {
protected:string name;
protected:string type;
protected:int damages;
public:
    /* Le Constructeur : */
    Weapon(string name, string type, int damages){
        this->name=name;
        this->type=type;
        this->damages=damages;
    }
    /* Les Getter : */
    string getName(){ return name; }

    string getType(){ return type; }

    int getDamages(){ return damages; }


};


#endif //RPG_WEAPON_H
