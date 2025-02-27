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
            //we can add some paenlties to player for overloaded inventory like slow movement, slow attackSpeed, not able to climb etc.
        } else if (currentWeight >= maxWeight * 0.75f) {
            weightStage = WeightStage::NEAR_FULL;
            //here also can add some penalties like slow movement(comparitivly faster than overloaded), slow attackSpeed,  etc.
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

    std::shared_ptr<InventorySlot> Inventory::getItem(const std::string& name) const
    {
        auto i = itemList.find(name);
        if (i != itemList.end()) {
            return i->second;
        }
        return nullptr;
    }

    //getList of item of specific type (ex.. if you want to sort all weapons)
    std::vector<std::shared_ptr<Item::Item>> Inventory::getItemByType(Item::ItemType type) const
    {
        std::vector<std::shared_ptr<Item::Item>> items;
        for (auto& i : itemList) {
            if (i.second->getItem()->getType() == type) {
                items.push_back(i.second->getItem());
            }
        }
        return items;
    }
}