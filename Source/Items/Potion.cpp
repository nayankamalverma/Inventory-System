#include "Potion.hpp"

namespace Item{
    
    postion::postion(const std::string& name, float weight,ItemRarity rarity, unsigned short maxStack, int health): Item(name, weight,rarity){
        this->health = health;
        SetType(ItemType::Consumables);
        SetMaxStack(maxStack);
    }

    int postion::getHealth() const
    {
        return health;
    }
    
}