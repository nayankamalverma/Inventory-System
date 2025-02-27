#pragma once
#include "Item.hpp"
#include <iostream>
#include <memory> 
#include <cstdint> 

namespace Inventory {
    class InventorySlot {
    private:
        std::shared_ptr<Item::Item> item;
        int quantity;
        uint16_t maxQuantity;

    public:
        InventorySlot(std::shared_ptr<Item::Item>& item, int quantity=1);
        virtual ~InventorySlot() = default;

        const std::shared_ptr<Item::Item>& getItem() const;  
        int getQuantity() const;
        void AddItem(int quantity=1);
        void RemoveItem(int quantity=1);
    };
}
