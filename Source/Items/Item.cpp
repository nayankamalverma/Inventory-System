#pragma once
#include <Item.hpp>

namespace Item
{
    Item::Item(const std::string& name,const std::string& description, float weight, ItemType type, ItemRarity rarity, uint16_t maxStack): name(name), description(description), weight(weight), type(type), rarity(rarity), maxStack(maxStack)
    {
    }


    const std::string& Item::getName() const
    {
        return name;
    }

    const std::string& Item::getDescription() const
    {
        return description;
    }
    

    float Item::getWeight() const
    {
        return weight;
    }

    void Item::setType(ItemType type)
    {
        this->type = type;
    }
    ItemType Item::getType() const
    {
        return type;
    }

    void Item::setRarity(ItemRarity rarity)
    {
        this->rarity = rarity;
    }

    ItemRarity Item::getRarity() const
    {
        return rarity;
    }

    void Item::setMaxStack(unsigned short maxStack)
    {
        this->maxStack = maxStack;
    }

    unsigned short Item::getMaxStack() const
    {
        return maxStack;
    }
}