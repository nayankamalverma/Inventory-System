#pragma once
#include <Item.hpp>

namespace Item
{
    Item::Item(std::string& name, float weight): name(name), weight(weight){}

    std::string Item::getName() const
    {
        return name;
    }

    float Item::getWeight() const
    {
        return weight;
    }

    ItemType Item::getType() const
    {
        return type;
    }
}