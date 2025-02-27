#pragma once
#include <Item.hpp>

namespace Item
{
    Item::Item(std::string& name, float weight): name(name), weight(weight){}

    std::string Item::getName() const
    {
        return name;
    }

    std::string Item::getDescription() const
    {
        return description;
    }

    float Item::getWeight() const
    {
        return weight;
    }

    ItemType Item::getType() const
    {
        return type;
    }

    ItemRarity Item::getRarity() const
    {
        return rarity;
    }
}