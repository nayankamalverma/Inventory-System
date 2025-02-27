#include "InventorySlot.hpp"

namespace Inventory{
    InventorySlot::InventorySlot(std::shared_ptr<Item::Item>& item, int quantity): item(std::move(item)), quantity(quantity), maxQuantity(item->getMaxStack()){}

    const std::shared_ptr<Item::Item>& InventorySlot::getItem() const
    {
        return item;
    }

    int InventorySlot::getQuantity() const
    {
        return quantity;
    }

    void InventorySlot::AddItem(const int quantity)
    {
        if (quantity <= 0)
        {
            std::cout<<"Quantity must be greater than 0."<<std::endl;
        }
        int newQuantity = this->quantity + quantity;
        if(newQuantity > maxQuantity)
        {
            this->quantity = maxQuantity;
            std::cout<<"Added "<<maxQuantity-newQuantity<<" of this item. You have max quantity "<<getItem()->getName()<<std::endl;
            return;
        }else{
            this->quantity = newQuantity;
        }
    }

    void InventorySlot::RemoveItem(int quantity)
    {
        int newQuantity = this->quantity - quantity;
        if(newQuantity < 0 || newQuantity == 0)
        {
            this->quantity = 0;
            std::cout<<"Removed "<<quantity<<" of this item. You have 0 quantity of "<<getItem()->getName()<<std::endl;
        }else{
            this->quantity = newQuantity;
        }
    }
}