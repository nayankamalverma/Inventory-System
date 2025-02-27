#pragma once
#include <Item.hpp>

namespace Item
{
    Item::Item(const std::string& name, float weight, ItemRarity rarity): name(name), description(""), weight(weight), type(ItemType::Materials), rarity(rarity)
    {
        maxStack = 1;        
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

    void Item::SetType(ItemType type)
    {
        this->type = type;
    }
    ItemType Item::getType() const
    {
        return type;
    }

    void Item::SetRarity(ItemRarity rarity)
    {
        this->rarity = rarity;
    }

    ItemRarity Item::getRarity() const
    {
        return rarity;
    }

    void Item::SetMaxStack(unsigned short maxStack)
    {
        this->maxStack = maxStack;
    }

    unsigned short Item::getMaxStack() const
    {
        return maxStack;
    }
}