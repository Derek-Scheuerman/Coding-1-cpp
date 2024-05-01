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
// needs to interact with the player

// Item , weapon, consumable
class Item {
private:
  string name;
  int value;
  int durability;

public:
  Item() {
    name = "sword";
    value = 10;
    durability = 100;
  }
  Item(string name_, int value_, int durability_) {
    name = name_;
    value = value_;
    durability = durability_;
  }

  string getName() { return name; }
  int getValue() { return value; }
  int getDurability() { return durability; }
};

// enemy class, has health, item, and name
class Enemy {
private:
  int health;
  string name;
  Item weapon;

public:
  Enemy(int health_, string name_, Item weapon_) {
    health = health_;
    name = name_;
    weapon = weapon_;
  }

  int getHealth() { return health; }
  string getName() { return name; }
  Item getWeapon() { return weapon; }
  int getDamage() { return weapon.getValue(); }
  void takeDamage(int damage) { health -= damage; }
};

// player class , health, item

// Loop
// enemy interacts with player
// Ending
int main() {
  cout << "Hello World!\n";
  // make enemy
  Item sword("sword", 10, 100);
  Enemy enemy(100, "enemy", sword);
  cout << enemy.getName() << endl;
  cout << enemy.getHealth() << endl;
  cout << enemy.getWeapon().getName() << endl;

  // change to while player health > 0 ie not dead or enemy not dead
  while (player.getHealth() > 0 || enemy.getHealth() > 0) {
    // player deals damage to enemy
    // enemy deals damage to player
    // print out the result
    // continue till player or enemy is dead
  }
}