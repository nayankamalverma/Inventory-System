#pragma once
#include <vector>
#include "Item.hpp"

namespace Inventory {

    enum WeightStage {
        NORMAL,
        NEAR_FULL,
        OVERLOADED
    };

    class Inventory
    {
        private:
            std::vector<Item::Item> items;
            double maxWeight;
            double currentWeight;
        public:
            Inventory(double maxWeight);
            virtual ~Inventory();

            bool addItem(const Item::Item& item);
            WeightStage getWeightStage() const;
            double getCurrentWeight() const;
            double getMaxWeight() const;
            Item::Item getItemByType(Item::ItemType type) const;
    };
}