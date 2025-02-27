#pragma once
#include <vector>
#include <unordered_map>
#include "InventorySlot.hpp"

namespace Inventory {

    enum WeightStage {
        NORMAL,
        NEAR_FULL,
        OVERLOADED
    };

    class Inventory
    {
        private:
            std::unordered_map<std::string, std::shared_ptr<InventorySlot>> itemList;
            double maxWeight;
            double currentWeight;
            WeightStage weightStage;
            
            void updateWeightStage();
        public:
            Inventory(double maxWeight);
            virtual ~Inventory();

            void clearInventory();
            bool addItem(const std::shared_ptr<Item::Item>& item, int quantity = 1);
            bool removeItem(const std::string& name, int quantity = 1);
            WeightStage getWeightStage() const;
            double getCurrentWeight() const;
            double getMaxWeight() const;
            std::vector<std::shared_ptr<Item::Item>> getItemByType(Item::ItemType type) const;
    };
}