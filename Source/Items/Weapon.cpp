#include "Weapon.hpp"`

namespace Item{
    Weapon::Weapon(const std::string& name, float weight,ItemRarity rarity, unsigned short maxStack, int damage, float range,float criticalChance, float durability): Item(name, weight,rarity), damage(damage), range(range), criticalChance(criticalChance), durability(durability){
        SetType(ItemType::Weapon);
        SetMaxStack(maxStack);
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