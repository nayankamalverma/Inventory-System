#pragma once
#include<string>

namespace Item
{
    enum ItemType
    {
        Armor,
        Weapon,
        Materials,
        Consumables,
        Treasure,
    };

    enum ItemRarity
    {
        Common,
        Uncommon,
        Rare,
        Epic,
        Legendary,
    };

    class Item
    {
        private:
            std::string name;
            std::string description;
            float weight;
            ItemType type;
            ItemRarity rarity;

        public:
            Item(std::string& name, float weight);
            virtual ~Item();

            std::string getName() const;
            std::string getDescription() const;
            float getWeight() const;
            ItemType getType() const;
            ItemRarity getRarity() const;
    };
}