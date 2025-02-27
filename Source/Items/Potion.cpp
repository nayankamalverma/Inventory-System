#include "Potion.hpp"

namespace Item{
    
    Postion::Postion(const std::string& name,const std::string& description, float weight,ItemRarity rarity, unsigned short maxStack, int health): Item(name,description, weight,ItemType::Consumables,rarity,12), health(health){
    }

    int Postion::getHealth() const
    {
        return health;
    }
    
}