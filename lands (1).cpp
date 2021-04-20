#include "lands.h"

using namespace std;

Land* getRandomLand(){
    LandTypes selection = (LandTypes)(rand() % MAX_NUM_LANDS);
    
    switch(selection){
        case LAKE:
            return new Lake;
            break;
        case FOREST:
            return new Forest;
            break;
        case DESERT:
            return new Desert;
            break;
        case CAVE:
            return new Cave;
            break;
        case TEMPLE:
            return new Temple;
            break;
        case TOWN:
            return new Town;
            break;
        case FIELD:
            return new Field;
            break;
        case CASTLE:
            return new Castle;
            break;
        default:
            return new Lake;
            break;
    }
    
}

string Lake::getShortDescription(){
    return "lake";
}

string Lake::getLongDescription(){
    return "You arrive at a large lake filled with clear sparkling water.";
}

string Lake::visit(Player& p){
    string description = "You drink from the lake, replenishing your thirst";
    p.setThirst(Player::DEFAULT_THIRST);
    return description;
}

string Forest::getShortDescription(){
    
    return "forest";
}

string Forest::getLongDescription(){
    return "You arrive in dense forest filled with trees and foliage.";
}

string Forest::visit(Player& p){
    string description = "You forage for berries but find nothing.";
    
    int chance = rand() % 100;
    
    // Chance to find berries
    if(chance > 50){
        description = "You foraged for berries in the forest and found some!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    // Chance to get mauled by bear
    if(chance < 10 && chance > 5){
        description = "You are attacked by a hungry bear in the woods!";
        p.setHealth(p.getHealth() - 1);
        return description;
    }
    
    // Chance to get double mauled
    if(chance < 5){
        description = "You are attacked by two very large bears!";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
        return description;
    }
    
    
    return description;
}

string Desert::getShortDescription(){
    
    return "desert";
}

string Desert::getLongDescription(){
    return "You arrive in a extremely hot, dry desert";
}

string Desert::visit(Player& p){
    string description = "The heat of the desert makes you dehydrated.";
    
    p.setThirst(p.getThirst() - 1);

    return description;
}

string Cave::getShortDescription(){
    
    return "cave";
}

string Cave::getLongDescription(){
    return "You decided to explore a cave system.";
}

string Cave::visit(Player& p){
    string description = "You explore the cave but find nothing.";
    int chance = rand() % 100;
    if (chance < 10){
        string description = "You find some old armor in the cave that gives you +5 health.";
        p.setHealth(p.getHealth() + 5);
        return description;
    }
    if (chance > 40){
        string description = "You find find some clean drinking water and some food.";
        p.setThirst(p.getThirst() + 1);
        p.setHunger(p.getHunger() + 1);
        return description;
    }

    return description;
}

string Temple::getShortDescription(){
    
    return "temple";
}

string Temple::getLongDescription(){
    return "You arrive at a temple, who knows what treasures or horrors it contains.";
}

string Temple::visit(Player& p){
    string description = "Temple";
    int chance = rand() % 100;
    if(chance > 50){
        string description = "The Temple turns out to be a Temple of Doom, you barely escape with your life.";
        return description;
    }
    if(chance < 50){
        string description = "The Temple turns out to be a Temple of Doom, your legs are crushed by giant bowlder.";
        p.setHealth(p.getHealth() - 2);
        return description;
    }
    if(chance == 50){
        string description = "The Temple turns out to be a Temple of Doom, but you are able to steal a magical idle and escape with your life. The idle gives you extreme stamina.";
        p.setThirst(p.getThirst() + 25);
        p.setHunger(p.getHunger() + 25);
        return description;
    }

    return description;
}

string Town::getShortDescription(){
    
    return "town";
}

string Town::getLongDescription(){
    return "You arrive at an unknown town, you try and look for some help.";
}

string Town::visit(Player& p){
    string description = "You stumble across town looking for help but no one cares.";
    int chance = rand() % 100;
    if(chance > 75){
        string description = "You find a doctor who is willing to tend to your wounds.";
        p.setThirst(p.getThirst() + 2);
        p.setHunger(p.getHunger() + 2);
        p.setHealth(p.getHealth() + 2);
        return description;
    }
    if(chance < 30){
        string description = "You stumble into the local tavern, you get a drink but a bar fight breaks out and you are injured.";
        p.setThirst(p.getThirst() + 2);
        p.setHealth(p.getHealth() - 1);
        
    }
    

    return description;
}

string Field::getShortDescription(){
    
    return "field";
}

string Field::getLongDescription(){
    return "You find an open field full of potential food";
}

string Field::visit(Player& p){
    string description = "You were unsuccessful at hunting any food.";
    int chance = rand() % 100;
    if(chance > 50 && chance < 86){
        string description = "You were able to hunt some food down, you will eat well tonight.";
        p.setHunger(p.getHunger() + 3);
        return description;
    }
    if(chance > 85){
        string description = "You were able to hunt a lot of food, you will eat well tonight and for many more.";
        p.setHunger(p.getHunger() + 3);
        return description;
    }
    if(chance < 10){
        string description = "While you were hunting the animal saw you and charged you; you should seek medical help.";
        p.setHealth(p.getHealth() - 3);
        return description;
    }

    return description;
}

string Castle::getShortDescription(){
    
    return "castle";
}

string Castle::getLongDescription(){
    return "You arrive at a huge abandoned castle, you go in looking for anything that can help.";
}

string Castle::visit(Player& p){
    string description = "You explored the castle but found nothing.";
    int chance = rand() % 100;
    if(chance > 75){
        string description = "You run into the Dragon guarding the treasure of the castle, you try to escape but you are burned.";
        p.setHealth(p.getHealth() - 2);
        return description;
    }
    if(chance > 45 && chance < 76){
        string description = "You find the remains of some crispy warriors, you take their armor.";
        p.setHealth(p.getHealth() + 2);
        return description;
    }
    if(chance < 10){
        string description = "You were able to sneak by the Dragon and discover a king's set of armor. You quickly put it on and escape the castle.";
        p.setHealth(p.getHealth() + 7);
        return description;
    }

    return description;
}