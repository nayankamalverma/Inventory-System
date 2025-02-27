#pragma once
#include "Item.hpp"

namespace Item
{
    class Weapon : public Item
    {
        private:
            int damage;
            float range;
            float criticalChance;
            float durability;
        public:
            Weapon(const std::string& name, float weight,ItemRarity rarity,unsigned short maxStack, int damage, float range,float criticalChance, float durability);
            virtual ~Weapon() = default;

            int getDamage() const;
            float getRange() const;
            float getCriticalChance() const;
            float getDurability() const;
    };
}