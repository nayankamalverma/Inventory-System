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
            WeightStage weightStage;

        public:
            Inventory(double maxWeight);
            virtual ~Inventory();

            bool addItem(const Item::Item& item);
            bool removeItem(const std::string& name);
            WeightStage getWeightStage() const;
            void updateWeightStage();
            double getCurrentWeight() const;
            double getMaxWeight() const;
            std::vector<int> getItemByType(Item::ItemType type) const;
    };
}