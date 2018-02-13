//
// Created by Kirian on 13/02/2018.
//

#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H
#include <string>
#include "Weapon.h"

using namespace std;


class Player {
protected:string name;
    int hp;
    long xp;

    /* Les Constructeurs : */
    Player(string name, int hp){
        this->name=name;
        this->hp=hp;
    }

    /* Les Getter/Setter : */
    string getName(){ return name; }

    int getHp(){ return hp; }

    void setHp(int hp){ this->hp=hp;	}

    long getXp(){ return xp; }

    void setXp(long xp){ this->xp=xp; }

    Weapon getWeapon(){ return weapon; }

    void setWeapon(Weapon weapon){ this.weapon=weapon; }

    /* Le combat : */
    void attaquer(Monster leMonstre){
        System.out.println("------------");
        System.out.println(this.getName() + " attque un " + leMonstre.getName() );
        System.out.println("------------");

        while (leMonstre.getHp() >0 && this.getHp() > 0 ){

            Random r = new Random();

            int dmgForMonster = r.nextInt(this.weapon.getDamages()) + 1;
            int cc = r.nextInt(2);

            String etatCc ="Coup normal. ";
            if (cc==0){
                dmgForMonster *=2;
                etatCc ="Coup Critique !";
            }

            leMonstre.looseHp(dmgForMonster);
            System.out.println(etatCc +" "+ this.getName() + " inflige " + dmgForMonster +" points de dégats au " + leMonstre.getName() );

            int dmgForMPlayer = leMonstre.getDamages();
            this.setHp(getHp() - dmgForMPlayer);
            System.out.println(leMonstre.getName() + " inflige " + dmgForMPlayer +" points de dégats a " + this.getName() );
        }

        if (leMonstre.getHp() <= 0){
            this.setXp(this.getXp() + 10);
            System.out.println("------------");
            System.out.println("Le monstre est mort. "+ this.getName() + " gagne 10 d'experience" );
            System.out.println("------------");
        }
        if (this.getHp() <= 0){
            this.setXp(0);
            System.out.println("------------");
            System.out.println("Le joueur est mort. Son experience tombe a zero");
            System.out.println("------------");
        }

    }

    /* Le Loot : */
    void looter(Lootable monLoot){
        System.out.println(this.getName() + "vient de récupérer un loot ! Il s'agit d'un "+ monLoot.getLoot());
    }

    /* La description : */
    void describe() throws PlayerDeadException{
            if (this.getHp() <= 0){
                System.out.println("Le joueur "+ name +" ne peut pas se décrire puisqu'il est mort." );
                throw new PlayerDeadException(this);
            } else {
                System.out.println("Le joueur "+ name +" a "+ hp +"pdv, et une arme "+ this.weapon.getName() +" de type "+ this.weapon.getType() +" qui fait en dégats "+ this.weapon.getDamages() );
            }
    }
};


#endif //RPG_PLAYER_H
