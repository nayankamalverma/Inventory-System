#pragma once
#include "Item.hpp"

namespace Item {
    class  postion : public Item
    {
        private:
            int health;
        public:
            postion(const std::string& name, float weight,ItemRarity rarity,unsigned short maxStack, int health);
            virtual ~postion() = default;

            int getHealth() const;
    };
    
}