#pragma once
#include<string>

namespace Item
{
    enum class ItemType
    {
        Armor,
        Weapon,
        Materials,
        Consumables,
        Treasure,
    };

    enum class ItemRarity
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
            unsigned short maxStack;

        public:
            Item(const std::string& name, const std::string& description, float weight, ItemType type, ItemRarity rarity, unsigned short maxStack);
            virtual ~Item() = default;

            const std::string& getName() const;     
            const std::string& getDescription() const;
            float getWeight() const;             
            void setType(ItemType type);
            ItemType getType() const; 
            void setRarity(ItemRarity rarity);
            ItemRarity getRarity() const;
            void setMaxStack(unsigned short maxStack);
            unsigned short getMaxStack() const;
    };
}