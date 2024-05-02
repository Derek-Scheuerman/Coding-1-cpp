#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// HOMEWORK create BASIC adventure functionality using the enemy class for each
// encounter. each enemy must use a weapon. each enemy has health. player has
// option of using weapon or consumable at least one encounter, to the death. i
// am grading based on the enemy class, does it have the functionality that it
// needs to interact with the player */

enum itemType { weapon, consumable, misc, I_last };
vector<string> itemTypeNames = {"Weapon", "Consumable", "Misc"};
enum weaponType { sword, bow, staff, club, dagger, axe, spear, scythe, W_last };
vector<string> weaponTypeNames = {"Sword",  "Bow", "Staff", "Club",
                                  "Dagger", "Axe", "Spear", "Scythe"};
enum consumableType { health, mana, stamina, C_last };
vector<string> consumableTypeNames = {"Health", "Mana", "Stamina"};
enum miscType { key, potion, scroll, M_last };
vector<string> miscTypeNames = {"Key", "Potion", "Scroll"};
enum elementType {
  basic,
  fire,
  ice,
  earth,
  air,
  water,
  lightning,
  darkness,
  EL_last
};
vector<string> elementTypeNames = {"Basic", "Fire",  "Ice",       "Earth",
                                   "Air",   "Water", "Lightning", "Darkness"};
enum enemyType { goblin, skeleton, zombie, orc, ghost, EN_last };
vector<string> enemyNames = {"Goblin", "Skeleton", "Zombie", "Orc", "Ghost"};
enum classType { warrior, mage, rogue, cleric, ranger, CL_last };
vector<string> classNames = {"Warrior", "Mage", "Rogue", "Cleric", "Ranger"};
enum raceType { human, elf, dwarf, dragonian, halfling, race_last };
vector<string> raceNames = {"Human", "Elf", "Dwarf", "Dragonian", "Halfling"};

// Check to see if a string is a number
bool checkIfANumber(string input) {
  return all_of(input.begin(), input.end(), ::isdigit);
}

class Item {
private:
  string name;
  itemType type;
  int value;
  weaponType weaponT;
  consumableType consumableT;
  miscType miscT;
  elementType element;
  bool isElemental;
  int elementalDamage = 10;

public:
  // (bool defaultWeapon, itemType t, weaponType w = sword, elementType e =
  // basic, string n = "Sword", int v = 40)
  Item(bool defaultWeapon, itemType t, weaponType w = sword,
       elementType e = basic, string n = "Sword", int v = 40) {
    setType(t);
    if (defaultWeapon) {
      setWeaponTypeDefault(w);
      setElementTypeDefault(e);
    } else {
      setValue(v);
      setName(n);
      setWeaponType(w);
      setElmentType(e);
    }

    if (element == basic) {
      isElemental = false;
    } else {
      isElemental = true;
    }
  }
  //(bool defaultConsumable, itemType t, consumableType conType = health, string
  // n = "Health Potion", int v = 20)
  Item(bool defaultConsumable, itemType t, consumableType conType = health,
       string n = "Health Potion", int v = 20) {
    setType(t);
    if (defaultConsumable) {
      setConsumableTypeDefault(conType);
    } else {
      setConsumableType(conType);
      setName(n);
      setValue(v);
    }
  }
  // (bool defaultMisc, itemType t, miscType m = key, string n = "Key", int v =
  // 1)
  Item(bool defaultMisc, itemType t, miscType m = key, string n = "Key",
       int v = 1) {
    setType(t);
    if (defaultMisc) {
      setMiscTypeDefault(m);
    } else {
      setMiscType(m);
      setName(n);
      setValue(v);
    }
  }
  // Error Item
  Item() { name = "Error Empty Item"; }

  string getName() { return name; }
  string getType() {
    for (int i = 0; i < I_last; i++) {
      if (i == type) {
        return itemTypeNames[i];
      }
    }
    return "Error";
  }
  itemType getTypeEnum() { return type; }
  int getValue() { return value; }
  string getWeaponType() {
    for (int i = 0; i < W_last; i++) {
      if (weaponT == i) {
        return weaponTypeNames[i];
      }
    }
    return "error";
  }
  weaponType getWeaponTypeEnum() { return weaponT; }
  string getConsumableType() {
    for (int i = 0; i < C_last; i++) {
      if (consumableT == i) {
        return consumableTypeNames[i];
      }
    }
    return "error";
  }
  consumableType getConsumableTypeEnum() { return consumableT; }
  string getMiscType() {
    for (int i = 0; i < M_last; i++) {
      if (miscT == i) {
        return miscTypeNames[i];
      }
    }
    return "error";
  }
  miscType getMiscTypeEnum() { return miscT; }
  string getElement() {
    for (int i = 0; i < EL_last; i++) {
      if (element == i) {
        return elementTypeNames[i];
      }
    }
    return "error";
  }
  elementType getElementTypeEnum() { return element; }
  bool getIsElemental() { return isElemental; }
  int getElementalDamage() { return elementalDamage; }
  void printInfo() {
    cout << "--------------------\n";
    cout << "- " << name << "\n";
    cout << "Item Type: " << getType() << "\n";
    cout << "Value: " << value << "\n";
    switch (type) {
    case weapon:
      cout << "Weapon Type: " << getWeaponType() << "\n";
      cout << "Element: " << getElement() << "\n";
      break;
    case consumable:
      cout << "Consumable Type: " << getConsumableType() << "\n";
      break;
    case misc:
      cout << "Misc Type: " << getMiscType() << "\n";
      break;
    default:
      cout << "Error: Item Type not found\n";
      break;
    }
    cout << "--------------------\n\n";
  }

  void setName(string n) { name = n; }
  void setType(itemType t) {
    if (t >= I_last || t < 0) {
      cout << "Invalid type" << endl;
    } else {
      switch (t) {
      case weapon:
        weaponT = sword;
        break;
      case consumable:
        consumableT = health;
        break;
      case misc:
        miscT = key;
        break;
      default:
        cout << "Error: Item Type not found\n";
        break;
      }
      type = t;
    }
  }
  void setValue(int v) { value = v; }
  void setWeaponTypeDefault(weaponType w) {
    if (w < 0 || w >= W_last) {
      cout << "Invalid weapon type" << endl;
      return;
    }
    if (type == weapon) {
      weaponT = w;
    } else {
      cout << "Must change item type first!" << endl;
      return;
    }
    for (int i = 0; i < W_last; i++) {
      if (weaponT == i) {
        name = weaponTypeNames[i];
        value = i * 5;
        return;
      }
    }
    name = "Error";
    value = 0;
  }
  void setWeaponType(weaponType w) {
    if (w < 0 || w >= W_last) {
      cout << "Invalid weapon type" << endl;
      return;
    }
    if (type == weapon) {
      weaponT = w;
    } else {
      cout << "Must change item type first!" << endl;
      return;
    }
  }
  void setConsumableTypeDefault(consumableType c) {
    if (c < 0 || c >= C_last) {
      cout << "Invalid consumable type" << endl;
      return;
    }
    if (type == consumable) {
      consumableT = c;
    } else {
      cout << "Must change item type first!" << endl;
      return;
    }
    for (int i = 0; i < C_last; i++) {
      if (consumableT == i) {
        name = consumableTypeNames[i];
        value = i * 5;
        return;
      }
    }
    name = "Error";
    value = 0;
  }
  void setConsumableType(consumableType c) {
    if (c < 0 || c >= C_last) {
      cout << "Invalid consumable type" << endl;
      return;
    }
    if (type == consumable) {
      consumableT = c;
    } else {
      cout << "Must change item type first!" << endl;
      return;
    }
  }
  void setElementTypeDefault(elementType e) {
    if (e < 0 || e >= EL_last) {
      cout << "Invalid element type" << endl;
      return;
    }
    if (type != weapon) {
      cout << "Must change item type first!" << endl;
      return;
    }
    element = e;
    if (e != basic) {
      isElemental = true;
      for (int i = 0; i < EL_last; i++) {
        if (element == i) {
          name = elementTypeNames[i] + name;
        }
      }
      name = "error";
    } else {
      isElemental = false;
    }
  }
  void setElmentType(elementType e) {
    if (e < 0 || e >= EL_last) {
      cout << "Invalid element type" << endl;
      return;
    }
    if (type != weapon) {
      cout << "Must change item type first!" << endl;
      return;
    }
    element = e;
    if (e != basic) {
      isElemental = true;
    } else {
      isElemental = false;
    }
  }
  void setMiscTypeDefault(miscType m) {
    if (m < 0 || m >= M_last) {
      cout << "Invalid misc type" << endl;
      return;
    }
    if (type == misc) {
      miscT = m;
    } else {
      cout << "Must change item type first!" << endl;
      return;
    }
    for (int i = 0; i < M_last; i++) {
      if (miscT == i) {
        name = miscTypeNames[i];
        value = 1;
        return;
      }
    }
    name = "Error";
    value = 0;
  }
  void setMiscType(miscType m) {
    if (m < 0 || m >= M_last) {
      cout << "Invalid misc type" << endl;
      return;
    }
    if (type == misc) {
      miscT = m;
    } else {
      cout << "Must change item type first!" << endl;
      return;
    }
  }
  void setElementalDamageDefault() { elementalDamage = 10; }
  void setElementalDamage(int d) { elementalDamage = d; }
};

class Inventory {
private:
  vector<Item> items;

public:
  void printInventory() {
    if (items.size() == 0) {
      cout << "Inventory is empty" << endl;
      return;
    }
    for (int i = 0; i < items.size(); i++) {
      items[i].printInfo();
    }
  }
  void printInventory(string n) {
    cout << "--------------------------------\n";
    cout << "- " << n << "\n";
    if (items.size() == 0) {
      cout << "Inventory is empty" << endl;
      return;
    }
    for (int i = 0; i < items.size(); i++) {
      items[i].printInfo();
    }
  }
  void printInventory(itemType t, string n) {
    cout << "--------------------------------\n";
    cout << "- " << n << "\n";
    if (items.size() <= 0) {
      cout << "Inventory is empty" << endl;
      return;
    }
    switch (t) {
    case weapon:
      cout << "Weapons:" << endl;
      for (int i = 0; i < items.size(); i++) {
        if (items[i].getTypeEnum() == weapon) {
          items[i].printInfo();
        }
      }
      break;
    case consumable:
      cout << "Consumables:" << endl;
      for (int i = 0; i < items.size(); i++) {
        if (items[i].getTypeEnum() == consumable) {
          items[i].printInfo();
        }
      }
      break;
    case misc:
      cout << "Miscellaneous:" << endl;
      for (int i = 0; i < items.size(); i++) {
        if (items[i].getTypeEnum() == misc) {
          items[i].printInfo();
        }
      }
      break;
    default:
      cout << "Invalid item type" << endl;
      break;
    }

    cout << endl;
  }
  void addItem(Item item, string n) {
    cout << "Adding: '" << item.getName() << "' to " << n
         << "'s inventory: " << endl;
    item.printInfo();
    items.push_back(item);
  }
  void removeItem(Item item) {
    if (items.size() == 0) {
      cout << "Inventory is empty" << endl;
      return;
    } else {
      for (int i = 0; i < items.size(); i++) {
        if (items[i].getName() == item.getName()) {
          cout << "Item: " << items[i].getName() << " removed!" << endl;
          items[i].printInfo();
          items.erase(items.begin() + i);
          return;
        }
      }
      cout << "Item not found" << endl;
    }
  }
  bool removeItem(string n) {
    if (items.size() == 0) {
      cout << "Inventory is empty" << endl;
      return false;
    } else {
      for (int i = 0; i < items.size(); i++) {
        if (items[i].getName() == n) {
          cout << "Item: " << items[i].getName() << " removed!" << endl;
          items[i].printInfo();
          items.erase(items.begin() + i);
          return true;
        }
      }
      cout << "Item not found" << endl;
      return false;
    }
  }

  Item getItem(string name) {
    if (items.size() == 0) {
      cout << "Inventory is empty" << endl;
      return Item();
    }
    for (int i = 0; i < items.size(); i++) {
      if (items[i].getName() == name) {
        return items[i];
      } else {
        cout << "Item not found" << endl;
        return Item();
      }
    }
    return Item();
  }
  vector<Item> getItemsByElement(elementType e) {
    vector<Item> itemsByElement;
    if (items.size() == 0) {
      cout << "Inventory is empty" << endl;
      return itemsByElement;
    }
    for (int i = 0; i < items.size(); i++) {
      if (items[i].getElementTypeEnum() == e) {
        itemsByElement.push_back(items[i]);
      }
    }
    return itemsByElement;
  }
  vector<Item> getItemsByType(itemType t) {
    vector<Item> itemsByType;
    if (items.size() == 0) {
      cout << "Inventory is empty" << endl;
      return itemsByType;
    }
    for (int i = 0; i < items.size(); i++) {
      if (items[i].getTypeEnum() == t) {
        itemsByType.push_back(items[i]);
      }
    }
    return itemsByType;
  }
  vector<Item> getItemsByWeaponType(weaponType w) {
    vector<Item> itemsByWeaponType;
    if (items.size() == 0) {
      cout << "Inventory is empty" << endl;
      return itemsByWeaponType;
    }
    for (int i = 0; i < items.size(); i++) {
      if (items[i].getWeaponTypeEnum() == w) {
        itemsByWeaponType.push_back(items[i]);
      }
    }
    return itemsByWeaponType;
  }
  vector<Item> getItemsByConsumableType(consumableType c) {
    vector<Item> itemsByConsumableType;
    if (items.size() == 0) {
      cout << "Inventory is empty" << endl;
      return itemsByConsumableType;
    }
    for (int i = 0; i < items.size(); i++) {
      if (items[i].getConsumableTypeEnum() == c) {
        itemsByConsumableType.push_back(items[i]);
      }
    }
    return itemsByConsumableType;
  }
  vector<Item> getItemsByMiscType(miscType m) {
    vector<Item> itemsByMiscType;
    if (items.size() == 0) {
      cout << "Inventory is empty" << endl;
      return itemsByMiscType;
    }
    for (int i = 0; i < items.size(); i++) {
      if (items[i].getMiscTypeEnum() == m) {
        itemsByMiscType.push_back(items[i]);
      }
    }
    return itemsByMiscType;
  }
  Item getItem(int index) {
    if (items.size() == 0) {
      cout << "Inventory is empty" << endl;
      return Item();
    }
    if (index < 0 || index >= items.size()) {
      cout << "Index out of range" << endl;
      return Item();
    }
    return items[index];
  }
  int getItemIndex(string name) {
    if (items.size() == 0) {
      cout << "Inventory is empty" << endl;
      return -1;
    }
    for (int i = 0; i < items.size(); i++) {
      if (items[i].getName() == name) {
        return i;
      }
    }
    return -1;
  }
  int getItemValue(string name) {
    if (items.size() == 0) {
      cout << "Inventory is empty" << endl;
      return -1;
    }
    for (int i = 0; i < items.size(); i++) {
      if (items[i].getName() == name) {
        return items[i].getValue();
      }
    }
    return -1;
  }
  int getItemValue(Item item) {
    if (items.size() == 0) {
      cout << "Inventory is empty" << endl;
      return -1;
    }
    for (int i = 0; i < items.size(); i++) {
      if (items[i].getName() == item.getName()) {
        return items[i].getValue();
      }
    }
    return -1;
  }
  int getTotalValue(itemType type) {
    if (items.size() == 0) {
      cout << "Inventory is empty" << endl;
      return 0;
    }
    int value = 0;
    for (int i = 0; i < items.size(); i++) {
      if (items[i].getTypeEnum() == type) {
        value += items[i].getValue();
      }
    }
    return value;
  }
  int getTotalElementalDamage(itemType type) {
    if (items.size() == 0) {
      cout << "Inventory is empty" << endl;
      return 0;
    }
    int value = 0;
    for (int i = 0; i < items.size(); i++) {
      if (items[i].getTypeEnum() == type && items[i].getIsElemental()) {
        value += items[i].getElementalDamage();
      }
    }
    return value;
  }
  int getSize() { return items.size(); }
  void clear() { items.clear(); }
};

class Enemy {
private:
  int health;
  string name;
  enemyType type;
  int baseDamage;
  int damage;
  int level = 1;
  int exp;
  int gold;
  int goldDroppedMin;
  int goldDroppedMax;
  Inventory inventory;

public:
  Enemy() {
    setTypeDefault();
    setNameDefault();
    setLevelDefault();
    setHealthDefault();
    setDamageDefault();
    setExpDefault();
    setGoldDefault();
    setGoldDroppedMinDefault();
    setGoldDroppedMaxDefault();
    baseDamage = damage;
  }
  Enemy(enemyType t) {
    setType(t);
    setNameDefault();
    setLevelDefault();
    setHealthDefault();
    setDamageDefault();
    setExpDefault();
    setGoldDefault();
    setGoldDroppedMinDefault();
    setGoldDroppedMaxDefault();
    baseDamage = damage;
  }
  Enemy(enemyType t, int lvl) {
    setType(t);
    setNameDefault();
    setLevel(lvl);
    setHealthDefault();
    setDamageDefault();
    setExpDefault();
    setGoldDefault();
    setGoldDroppedMinDefault();
    setGoldDroppedMaxDefault();
    baseDamage = damage;
  }
  Enemy(int hp, string n, enemyType t, int dam, int lvl, int ex, int g,
        int gDMin, int gDMax) {
    health = hp;
    name = n;
    type = t;
    damage = dam;
    level = lvl;
    exp = ex;
    gold = g;
    goldDroppedMin = gDMin;
    goldDroppedMax = gDMax;
    baseDamage = damage;
  }

  int getHealth() { return health; }
  string getName() { return name; }
  string getType() {
    for (int i = 0; i < EL_last; i++) {
      if (type == (enemyType)i) {
        return enemyNames[i];
      }
    }
    return "Error";
  }
  int getDamage() { return damage; }
  int getLevel() { return level; }
  int getExp() { return exp; }
  int getGold() { return gold; }
  int getGoldDroppedMin() { return goldDroppedMin; }
  int getGoldDroppedMax() { return goldDroppedMax; }
  Inventory getInventory() { return inventory; }

  void setLevel(int l) { level = l; }
  void setLevelDefault() { level = 1; }
  void setType(enemyType t) {
    if (t >= EN_last || t < 0) {
      cout << "Invalid type" << endl;
    } else {
      type = (enemyType)t;
    }
  }
  void setTypeDefault() { type = (enemyType)(rand() % (EN_last - 1)); }
  void setName(string n) { name = n; }
  void setNameDefault() { name = enemyNames[type]; }
  void setHealth(int h) { health = h; }
  void setHealthDefault() { health = 10 * level; }
  void setDamage(int d) {
    damage = d;
    baseDamage = d;
  }
  void setDamageDefault() {
    damage = 2 * level * (type + 1);
    baseDamage = damage;
  }
  void setExp(int e) { exp = e; }
  void setExpDefault() { exp = 10 * level; }
  void setGold(int g) { gold = g; }
  void setGoldDefault() { gold = 1 * level; }
  void setGoldDroppedMin(int g) { goldDroppedMin = g; }
  void setGoldDroppedMinDefault() { goldDroppedMin = 1 * level; }
  void setGoldDroppedMax(int g) { goldDroppedMax = g; }
  void setGoldDroppedMaxDefault() { goldDroppedMax = 2 * level; }
  void updateDamage() {
    damage = baseDamage + inventory.getTotalValue(weapon) +
             inventory.getTotalElementalDamage(weapon);
  }
  void takeDamage(int dmg) { health -= dmg; }
  int attack() {
    updateDamage();
    return damage;
  }
  void printInfo() {
    cout << "--------------------\n";
    cout << "- " << name << "\n";
    cout << "Enemy Type: " << getType() << "\n";
    cout << "Level: " << level << "\n";
    cout << "Health: " << health << "\n";
    cout << "Damage: " << damage << "\n";
    cout << "--------------------\n\n";
  }
  void printInv() { inventory.printInventory(name); }
  void printInv(itemType t) { inventory.printInventory(t, name); }
  void addItem(Item item) { inventory.addItem(item, name); }
  void removeItem(Item item) { inventory.removeItem(item); }
};

class Player {
private:
  int level = 1;
  int baseHealth;
  int health;
  int baseDamage;
  int damage;
  string name;
  int expToLevel;
  int exp;
  int gold;
  raceType race;
  Inventory inventory;

public:
  Player() {
    level = 1;
    baseHealth = 100;
    health = baseHealth;
    baseDamage = 10;
    damage = baseDamage;
    name = "Player";
    expToLevel = 10;
    exp = 0;
    gold = 0;
    race = human;
    inventory.clear();
  }
  Player(string n) {
    level = 1;
    baseHealth = 100;
    health = baseHealth;
    baseDamage = 10;
    damage = baseDamage;
    name = n;
    expToLevel = 10;
    exp = 0;
    gold = 0;
    race = human;
    inventory.clear();
  }
  Player(string n, raceType r) {
    level = 1;
    baseHealth = 100;
    health = baseHealth;
    baseDamage = 10;
    damage = baseDamage;
    name = n;
    expToLevel = 10;
    exp = 0;
    gold = 0;
    race = r;
    inventory.clear();
  }
  Player(string n, raceType r, int lvl) {
    level = lvl;
    baseHealth = 100 + (lvl * 5);
    health = baseHealth;
    baseDamage = 10 + (lvl * 2);
    damage = baseDamage;
    name = n;
    expToLevel = 10 + (lvl * 10);
    exp = 0;
    gold = 0;
    race = r;
    inventory.clear();
  }
  Player(string n, raceType r, int lvl, int hp, int dam) {
    level = lvl;
    baseHealth = hp;
    health = baseHealth;
    baseDamage = dam;
    damage = baseDamage;
    name = n;
    expToLevel = 10 + (lvl * 10);
    exp = 0;
    gold = 0;
    race = r;
    inventory.clear();
  }
  Player(string n, raceType r, int lvl, int hp, int dam, int g) {
    level = lvl;
    baseHealth = hp;
    health = baseHealth;
    baseDamage = dam;
    damage = baseDamage;
    name = n;
    expToLevel = 10 + (lvl * 10);
    exp = 0;
    gold = g;
    race = r;
    inventory.clear();
  }
  Player(string n, raceType r, int lvl, int hp, int dam, int g, int e) {
    level = lvl;
    baseHealth = hp;
    health = baseHealth;
    baseDamage = dam;
    damage = baseDamage;
    name = n;
    expToLevel = 10 + (lvl * 10);
    exp = e;
    gold = g;
    race = r;
    inventory.clear();
  }

  int getLevel() { return level; }
  int getBaseHealth() { return baseHealth; }
  int getHealth() { return health; }
  int getBaseDamage() { return baseDamage; }
  int getDamage() { return damage; }
  string getName() { return name; }
  int getExpToLevel() { return expToLevel; }
  int getExp() { return exp; }
  int getGold() { return gold; }
  raceType getRaceType() { return race; }
  string getRace() { return raceNames[race]; }

  Inventory getInventory() { return inventory; }

  void setLevel(int l) { level = l; }
  void setLevelDefault() { level = 1; }
  void setBaseHealth(int h) { baseHealth = h; }
  void setHealth(int h) { health = h; }
  void setBaseDamage(int d) { baseDamage = d; }
  void setDamage(int d) { damage = d; }
  void setName(string n) { name = n; }
  void setExpToLevel(int e) { expToLevel = e; }
  void setExp(int e) { exp = e; }
  void setGold(int g) { gold = g; }
  void setInventory(Inventory i) { inventory = i; }
  void updateDamage() {
    damage = baseDamage + inventory.getTotalValue(weapon) +
             inventory.getTotalElementalDamage(weapon);
  }
  void attack(Enemy &enemy) {
    enemy.takeDamage(damage);
    cout << name << " attacks " << enemy.getName() << " for " << damage
         << " damage!" << endl;
  }
  void heal(int amount) { health += amount; }
  void takeDamage(int dmg, string n) {
    cout << n << " attacks " << name << " for " << dmg << " damage!" << endl;
    health -= dmg;
  }
  void addItem(Item item) { inventory.addItem(item, name); }
  void removeItem(Item item) { inventory.removeItem(item); }
  bool removeItem(string itemName) { return inventory.removeItem(itemName); }
  void useItem(string itemName) {
    if (inventory.getSize() == 0) {
      cout << "Inventory is empty" << endl;
    } else if (inventory.getItemValue(itemName) == -1) {
      cout << "Item not found" << endl;
    } else {
      Item item = inventory.getItem(itemName);
      if (item.getTypeEnum() == consumable) {
        if (item.getConsumableTypeEnum() == health) {
          heal(item.getValue());
          cout << name << " uses " << itemName << " and heals for "
               << item.getValue() << " health!" << endl;
          inventory.removeItem(item);
        }
      }
    }
  }
  void useItem(Item item) {
    if (inventory.getSize() == 0) {
      cout << "Inventory is empty" << endl;
    } else if (inventory.getItemValue(item) == -1) {
      cout << "Item not found" << endl;
    } else if (item.getTypeEnum() == consumable) {
      cout << "Using item: " << item.getName() << endl;
      int cT = item.getConsumableTypeEnum();
      switch (cT) {
      case 0:
        heal(item.getValue());
        break;
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      default:
        break;
      }
    } else {
      cout << "Item is not a consumable" << endl;
    }
  }
  void levelUp() {
    if (exp >= expToLevel) {
      exp -= expToLevel;
      level++;
      updateLvl();
    } else {
      cout << "Not enough exp to level up" << endl;
    }
  }
  void updateLvl() { expToLevel = 10 + (level * 10); }
  void printInventory() { inventory.printInventory(); }
  void printInv() { inventory.printInventory(name); }
  void printInv(itemType t) { inventory.printInventory(t, name); }
  // Manages the inventory. Players can add items to their inventory, remove
  // items from their inventory, and equip items.
  void InventoryF() {
    int inputInt = 0;
    string input = "";

    do {
      cout << "Do you want to (view = 1, remove = 2): ";
      cin >> input;
      if (checkIfANumber(input)) {
        inputInt = stoi(input);
      } else {
        cout << "Not a number.\n";
      }
      if (inputInt != 1 && inputInt != 2 && inputInt != 3) {
        cout << "Invalid input.\n";
      }
    } while (inputInt != 1 && inputInt != 2 && inputInt != 3);

    bool itemvalid = false;
    switch (inputInt) {
    case 1: // view
      printInv();
      break;
    case 2: // remove
      if (inventory.getSize() == 0) {
        cout << "You have nothing in your inventory.\n";
        break;
      }
      while (itemvalid) {
        cout
            << "What do you want to remove from your inventory? (q = cancel)\n";
        cin >> input;
        if (input == "q") {
          itemvalid = true;
          break;
        }
        itemvalid = removeItem(input);
      }
      break;
    default:
      cout << "Invalid input.\n";
      break;
    }
  }
  void printInfo() {
    cout << "--------------------\n";
    cout << "- " << name << "\n";
    cout << "Race: " << getRace() << "\n";
    cout << "Level: " << level << "\n";
    cout << "Gold: " << gold << "\n";
    cout << "Health: " << health << "\n";
    cout << "Damage: " << damage << "\n";
    cout << "--------------------\n\n";
  }
  void printAllInfo() {
    cout << "--------------------\n";
    cout << "- " << name << "\n";
    cout << "Race: " << getRace() << "\n";
    cout << "Level: " << level << "\n";
    cout << "Gold: " << gold << "\n";
    cout << "Health: " << health << "\n";
    cout << "Damage: " << damage << "\n";
    cout << "Exp: " << exp << "\n";
    cout << "Exp to level: " << expToLevel << "\n";
    printInventory();
  }

  // Asks the player a y/n question
  bool AskYesNo(string question) {
    string input;
    do {
      cout << question << " (y/n): ";
      cin >> input;
      if (input == "y") {
        return true;
      } else if (input == "n") {
        return false;
      }
      cout << "Must be lowercase y or n!\n";
    } while (input != "y" && input != "n");
    return false;
  }

  // Asks the player what actions they want to take such as see stats, see
  // inventory, etc.
  bool ActionQuestion(string question) {
    if (!AskYesNo("Skip action? ")) {
      do {
        if (AskYesNo("Do you want to see stats? ")) {
          printInfo();
        } else {
          break;
        }
      } while (true);
      do {
        if (AskYesNo("Do you want to interact with Inventory? ")) {
          InventoryF();
        } else {
          break;
        }
      } while (true);
      do {
        if (AskYesNo("Done with Actions?")) {
          cout << "You are done with your actions.\n\n";
          break;
        }
      } while (true);
    }
    return AskYesNo(question);
  }
};

raceType getPlayerRace() {
  int PlayerRace;
  string input;
  do {
    cout << "Choose your race:\n";
    for (int i = 0; i < race_last; i++) {
      cout << i << ": " << raceNames[i] << endl;
    }
    cin >> input;
    if (checkIfANumber(input)) {
      PlayerRace = stoi(input);
    } else {
      PlayerRace = -1;
    }
    if (PlayerRace < 0 || PlayerRace > race_last) {
      cout << "Invalid input. Please enter a number between 0 and " << race_last
           << ".\n";
    }
  } while (PlayerRace < 0 || PlayerRace > race_last);
  return static_cast<raceType>(PlayerRace);
}

void printTitle() {
  cout << "--------------------\n";
  cout << "-- Welcome to the --\n";
  cout << "- Dungeon Crawler -\n";
  cout << "--------------------\n\n";
}

void fightToTheDeath(Player &player, Enemy &enemy) {
  while (player.getHealth() > 0 && enemy.getHealth() > 0) {
    player.attack(enemy);
    enemy.printInfo();
    if (enemy.getHealth() <= 0) {
      cout << "You win!" << endl;
      cout << "You killed the " << enemy.getName() << "!\n";
      cout << "You gained " << enemy.getExp() << " exp and " << enemy.getGold()
           << " gold!" << endl;
      player.setExp(player.getExp() + enemy.getExp());
      player.setGold(player.getGold() + enemy.getGold());
      player.levelUp();
      cout << "You are now level " << player.getLevel() << "!\n";
      cout << "You have " << player.getExp() << " exp and need "
           << player.getExpToLevel() << " exp to level up!\n";

      break;
    } else {
      player.takeDamage(enemy.attack(), enemy.getName());
      player.printInfo();
      if (player.getHealth() <= 0) {
        cout << "You died!" << endl;
        cout << "You lost! " << enemy.getName() << " killed you!" << endl;
        break;
      }
    }
  }
}

int main() {
startover:
  srand(time(0));
  printTitle();

  // Create a player
  string PlayerName;
  raceType PlayerRace;
  cout << "What is your name? ";
  cin >> PlayerName;
  cout << "\nWelcome " << PlayerName << "!\n\n";
  PlayerRace = getPlayerRace();
  Player player1(PlayerName, PlayerRace);
  player1.printInfo();

  // Create items for the player and use a health potion
  Item item1(false, weapon, sword, basic, "Excal", 30);
  Item item2(true, consumable, health, "Health Potion", 20);
  player1.addItem(item1);
  player1.addItem(item2);
  player1.updateDamage();
  player1.useItem(item2);
  player1.removeItem(item2);
  player1.printAllInfo();

  // Create an enemy
  Enemy gob = Enemy(goblin);
  gob.addItem(Item(true, weapon, sword));
  gob.updateDamage();
  gob.printInfo();
  gob.printInv(weapon);

  // Fight enemy
  cout << "You encounter a " << gob.getName() << "!\n";
  gob.printInfo();
  fightToTheDeath(player1, gob);

  // Create some enemies
  vector<Enemy> enemies;
  enemies.push_back(Enemy(goblin));
  enemies.push_back(Enemy(goblin));
  enemies.push_back(Enemy(goblin));
  enemies.push_back(Enemy(skeleton));
  enemies.push_back(Enemy(skeleton));
  enemies.push_back(Enemy(skeleton));
  enemies.push_back(Enemy(zombie));
  enemies.push_back(Enemy(zombie));
  enemies.push_back(Enemy(zombie));
  enemies.push_back(Enemy(orc));
  enemies.push_back(Enemy(orc));
  enemies.push_back(Enemy(orc));
  enemies.push_back(Enemy(ghost));
  enemies.push_back(Enemy(ghost));
  enemies.push_back(Enemy(ghost));

  // Fight enemies
  for (int i = 0; i < enemies.size(); i++) {
    player1.updateDamage();
    enemies[i].updateDamage();
    cout << "You encounter a " << enemies[i].getName() << "!\n";
    fightToTheDeath(player1, enemies[i]);
    if (!player1.ActionQuestion("Would you like to continue?")) {
      cout << "Wow reallly?!?!?!?!?!?!?!?!?!?!?!?!\n";
      cout << "You are so boring!\n";
      cout << "I'm done with you!\n";
      return 0;
    } else {
      cout << "\n";
    }
    if (player1.getHealth() <= 0) {
      break;
    }
    if (i == enemies.size() - 1) {
      cout << "You have defeated all the enemies!\n";
      enemies.clear();
      if (player1.ActionQuestion("Would you like to restart?")) {
        goto startover;
      } else {
        cout << "Wow reallly?!?!?!?!?!?!?!?!?!?!?!?!\n";
        cout << "You are so boring!\n";
        cout << "I'm done with you!\n";
        return 0;
      }
      break;
    }
  }
  if (player1.getHealth() <= 0) {
    if (player1.ActionQuestion("Would you like to restart?")) {
      goto startover;
    } else {
      cout << "Wow reallly?!?!?!?!?!?!?!?!?!?!?!?!\n";
      cout << "You are so boring!\n";
      cout << "I'm done with you!\n";
      return 0;
    }
  }
}