#pragma once
#include "Item.hpp"

namespace Item {
    class  Postion : public Item
    {
        private:
            int health;
        public:
            Postion(const std::string& name,const std::string& description, float weight,ItemRarity rarity, unsigned short maxStack, int health);
            virtual ~Postion() = default;

            int getHealth() const;
    };
    
}