#pragma once
#include<string>

namespace Item
{
    enum ItemType
    {
        Weapon,
        Armor,
        Potion,
    };

    class Item
    {
        private:
            std::string name;
            float weight;
            ItemType type;

        public:
            Item(std::string& name, float weight);
            virtual ~Item();

            std::string getName() const;
            float getWeight() const;
            ItemType getType() const;
    };
}