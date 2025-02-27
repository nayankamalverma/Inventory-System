#include "Inventory.hpp"
#include "InventorySlot.hpp"

namespace Inventory{
    Inventory::Inventory(double maxWeight): maxWeight(maxWeight), currentWeight(0.0), weightStage(WeightStage::NORMAL){}

    Inventory::~Inventory()
    {
        clearInventory();
    }

    void Inventory::clearInventory()
    {
        itemList.clear();
        currentWeight = 0.0;
        updateWeightStage();
    }

    bool Inventory::addItem(const std::shared_ptr<Item::Item>& item, int quantity)
    {
        if(quantity <= 0)   return false;
        double addedWeight = item->getWeight() * quantity;
        // check if not overloaded then itemWeight +current should not go above max Weight (i.e. in case of near full)
        if(weightStage!= WeightStage::OVERLOADED && currentWeight + addedWeight > maxWeight)
        {
            return false;
        }
        // check if item already exists in inventory
        auto slot = itemList.find(item->getName());
        if (slot != itemList.end()) {// Item found
            slot->second->AddItem(quantity);
        } else { // Item not found. Create a new slot
            itemList[item->getName()] = std::make_shared<InventorySlot>(item, quantity);
        }
        currentWeight += addedWeight;
        updateWeightStage();
        return true; 
    }

    bool Inventory::removeItem(const std::string& name, int quantity)
    {
        if(quantity <= 0)   return false;
        auto i = itemList.find(name);
        if (i != itemList.end() && i->second->getQuantity() <= quantity) {
            currentWeight -= i->second->getQuantity() * i->second->getItem()->getWeight();
            i->second->RemoveItem(quantity);
            updateWeightStage();
            if(i->second->getQuantity() == 0) {itemList.erase(i);}                
            return true;
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
    }
}