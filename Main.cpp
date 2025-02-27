#include <memory>
#include <iostream>
#include "Weapon.hpp"
#include "Potion.hpp"
#include "Inventory.hpp"

using namespace std;

int main() {
    
    std::shared_ptr<Item::Item> sword = std::make_shared<Item::Weapon>("Sword", "A simple sword", 2.0, Item::ItemRarity::Common, 1, 10, 1.0, 0.1, 30.0);
    std::shared_ptr<Item::Item> healthPotion = std::make_shared<Item::Postion>("Heal","Health Potion", 1, Item::ItemRarity::Uncommon, 12, 10);

    std::unique_ptr<Inventory::Inventory> inventory = std::make_unique<Inventory::Inventory>(10.0);
    inventory->addItem(sword);
    inventory->addItem(healthPotion, 5);
    inventory->removeItem("Heal", 2);
    auto item = inventory->getItem("Heal");

    cout<<item->getItem()->getName()<<" avialable "<<  item->getQuantity();
}