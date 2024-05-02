#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum itemType { weapon, consumable, misc, I_last };
enum enemyType { goblin, skeleton, EN_last };
vector<string> enemyNames = {"Goblin", "Skeleton"};

class Item {
private:
  string name;
  int value;
  itemType type;

public:
  Item() {
    type = weapon;
    name = "Fist";
    value = 5;
  }
  Item(string n, itemType t) {
    name = n;
    type = t;
    switch (type) {
    case weapon:
      value = 5;
      break;
    case consumable:
      value = 10;
      break;
    case misc:
      value = 1;
      break;
    default:
      value = 0;
      break;
    }
  }
  Item(string n, int v, itemType t) {
    name = n;
    value = v;
    type = t;
  }

  string getName() { 
      return name; 
  }
  int getValue() { return value; }
  int getType() { return type; }

  void setName(string n) { name = n; }
  void setValue(int v) { value = v; }
  void setType(int t) { type = (itemType)t; }
};

class Enemy {
private:
  enemyType type;
  string name;
  int health;
  int damage;
  int baseDamage;
  vector<Item> inventory;

public:
  Enemy() {
    type = (enemyType)(rand() % (EN_last - 1));
    name = enemyNames[type];
    health = rand() % 100 + 1;
    damage = rand() % 10 + 1;
    baseDamage = damage;
  }
  Enemy(string n, int h, int d) {
    name = n;
    health = h;
    damage = d;
    baseDamage = d;
  }
  Enemy(enemyType t) {
    type = t;
    name = enemyNames[type];
    health = rand() % 100 + 1;
    damage = rand() % 10 + 1;
    baseDamage = damage;
  }
  string getName() { return name; }
  int getHealth() { return health; }
  int getDamage() { return damage; }
  int getType() { return type; }

  void setName(string n) { name = n; }
  void setHealth(int h) { health = h; }
  void setDamage(int d) { damage = d; }
  void setType(int t) { type = (enemyType)t; }
  void addItem(Item i) {
    inventory.push_back(i);
    updateDamage(i);
  }
  void removeItem(Item item) {
    for (int i = 0; i < inventory.size(); i++) {
      if (inventory[i].getName() == item.getName()) {
        inventory.erase(inventory.begin() + i);
      }
    }
  }
  void removeItem(string itemName) {
    for (int i = 0; i < inventory.size(); i++) {
      if (inventory[i].getName() == itemName) {
        inventory.erase(inventory.begin() + i);
      }
    }
  }
  void removeItem(int i) { inventory.erase(inventory.begin() + i); }
  void printInventory() {
    cout << "--------------------\n";
    cout << "Inventory: " << endl;
    for (int i = 0; i < inventory.size(); i++) {
      cout << i << ": " << inventory[i].getName() << endl;
    }
    cout << "--------------------\n";
  }

  int getTotalValue(itemType type) {
    if (inventory.size() == 0) {
      cout << "Inventory is empty" << endl;
      return 0;
    }
    int value = 0;
    for (int i = 0; i < inventory.size(); i++) {
      if (inventory[i].getType() == type) {
        value += inventory[i].getValue();
      }
    }
    return value;
  }
  vector<Item> getInventory() { return inventory; }
  void updateDamage() { damage = baseDamage + getTotalValue(weapon); }
  void updateDamage(Item item) {
    if (item.getType() == weapon) {
      damage = baseDamage + item.getValue();
    }
  }
  void printStats() {
    cout << "\n--------------------\n";
    cout << "Name: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Damage: " << damage << endl;
    cout << "baseDamage: " << baseDamage << endl;
    printInventory();
  }
};

int main() {
  cout << "Hello World!\n";
  Item i1;
  Item i2("Sword", weapon);
  Item i3("Potion", consumable);
  Item i4("Shield", 10, weapon);

  cout << i1.getName() << " " << i1.getValue() << " " << i1.getType() << endl;
  cout << i2.getName() << " " << i2.getValue() << " " << i2.getType() << endl;
  cout << i3.getName() << " " << i3.getValue() << " " << i3.getType() << endl;
  cout << i4.getName() << " " << i4.getValue() << " " << i4.getType() << endl;

  cout << "----------------\n\n";
  vector<Item> EN_inventory;

  Enemy e1;
  e1.addItem(i4);
  e1.addItem(i3);
  e1.addItem(i2);
  EN_inventory = e1.getInventory();
  e1.printInventory();

  Enemy e2("Goblin", 100, 10);
  e2.addItem(i1);
  for (int i = 0; i < EN_inventory.size(); i++) {
    e2.addItem(EN_inventory[i]);
  }

  Enemy e3("Skeleton", 100, 10);
  Item i5("Bat", 10, weapon);
  Item i6("man", 5, weapon);
  Item i7("health pot", 20, consumable);
  e3.printStats();
  e3.addItem(i5);
  e3.printStats();
  e3.addItem(i6);
  e3.printStats();
  e3.addItem(i7);
  e3.printStats();

  e2.printInventory();
  return 0;
}