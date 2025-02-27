#include "Weapon.hpp"`

namespace Item{
    Weapon::Weapon(const std::string& name,const std::string& description, float weight,ItemRarity rarity, unsigned short maxStack, int damage, float range,float criticalChance, float durability): Item(name,description, weight,rarity,ItemType::Weapon,maxStack), damage(damage), range(range), criticalChance(criticalChance), durability(durability){
    }

    int Weapon::getDamage() const
    {
        return damage;
    }

    float Weapon::getRange() const
    {
        return range;
    }

    float Weapon::getCriticalChance() const
    {
        return criticalChance;
    }

    float Weapon::getDurability() const
    {
        return durability;
    }
}