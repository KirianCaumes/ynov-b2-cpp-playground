//
// Created by Kirian on 13/02/2018.
//

#ifndef RPG_SHOP_H
#define RPG_SHOP_H


class Shop {
    Map<String, Integer> items;

    /* Le Constructeur : */
    Shop(){
        this.items= new HashMap<String, Integer>();
    }

    /* L'ajout d'item au magasin : */
    void addItemToShop(String bien, Integer prix){
        items.put(bien, prix);
        System.out.println("Ajout de l'objet "+ bien +" d'une valeur de "+ prix +"€ au magasin");
    }

    /* La recherche d'items moins chers : */
    List <String> getItemsCheaperThan(int montantMax){  // A mieux faire, même si l'affichage console est bon
        Set<String> mesItems = items.keySet();

        for (String mesItemsTotal : mesItems){
            Integer monPrix = items.get(mesItemsTotal);
            if (monPrix < montantMax ){
                System.out.println("Pour moins de "+ montantMax +"€ je peux avoir dans mon magasin un(e) " + mesItemsTotal);
            }
            else {
                System.out.println("Il n'y a rien dans ce magasin pour moins de "+ montantMax +"€");
                break;
            }
        }
        return null;
    }
};


#endif //RPG_SHOP_H
