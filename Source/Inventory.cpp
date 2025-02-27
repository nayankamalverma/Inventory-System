#include "Inventory.hpp"

namespace Inventory{
    Inventory::Inventory(double maxWeight): maxWeight(maxWeight), currentWeight(0.0){
        updateWeightStage();
    }

    bool Inventory::addItem(const Item::Item& item)
    {
        // check if not overloaded then itemWeight +current should not go above max Weight (i.e. in case of near full)
        if(weightStage!= WeightStage::OVERLOADED && currentWeight + item.getWeight() > maxWeight)
        {
            return false;
        }
        items.push_back(item);
        currentWeight += item.getWeight();
        updateWeightStage();
        return true;
    }

    bool Inventory::removeItem(const std::string& name)
    {
        for(int i = 0; i < items.size(); i++)
        {
            if(items[i].getName() == name)
            {
                currentWeight -= items[i].getWeight();
                items.erase(items.begin() + i);
                updateWeightStage();
                return true;
            }
        }
        return false;
    }

    WeightStage Inventory::getWeightStage() const
    {
        return weightStage;
    }

    void Inventory::updateWeightStage() {
        if (currentWeight >= maxWeight) {
            weightStage = WeightStage::OVERLOADED;
        } else if (currentWeight >= maxWeight * 0.75f) {
            weightStage = WeightStage::NEAR_FULL;
        } else {
            weightStage = WeightStage::NORMAL;
        }
    }

    double Inventory::getCurrentWeight() const
    {
        return currentWeight;
    }

    double Inventory::getMaxWeight() const
    {
        return maxWeight;
    }

    //getList of item of specific type (ex.. if you want to sort all weapons)
    std::vector<int> Inventory::getItemByType(Item::ItemType type) const
    {
        std::vector<int> indexes;
        for(int i = 0; i < items.size(); i++)
        {
            if(items[i].getType() == type)
            {
                indexes.push_back(i);
            }
        }
        return indexes;
    }

}