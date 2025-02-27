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
            unsigned short maxStack;

        public:
            Item(const std::string& name, float weight, ItemRarity rarity = ItemRarity::Common);
            virtual ~Item() ;

            const std::string& getName() const;     
            const std::string& getDescription() const;
            float getWeight() const;             
            void SetType(ItemType type);
            ItemType getType() const; 
            void SetRarity(ItemRarity rarity);
            ItemRarity getRarity() const;
            void SetMaxStack(unsigned short maxStack);
            unsigned short getMaxStack() const;
    };
}