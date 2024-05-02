// Adventure in C++
// Derek S.
// Maxed out CPU for replit can't add anymore otherwise it will crash

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Item info
struct Item {
  string name; //< search for this value
  bool isEquipped;
  int damage;
  int defense;
};

// Player info
int PlayerHP = 100;
int PlayerGold = 0;
int PlayerAttack = 0;
int PlayerEqippedDamage = 0;
int PlayerEqippedDefense = 0;
int PlayerBlock = 3;
bool PlayerAlive = true;
bool PlayerWon = false;
string PlayerName = "";
string Location = "Home";
vector<Item> Inventory;

// Enemy info
struct Enemy {
  int ID; //< search for this value
  string name;
  int health;
  int attack;
  int block;
  int gold;
  bool isAlive;
};

// Enemies
vector<Enemy> Enemies = {};
// check RestartGame for adding enemies to this vector

// Fight info
int P_outcomedamage = 0;
int E_outcomedamage = 0;
int turns = 0;
int currentEnemy = 0;

void RestartGame() {
  currentEnemy = 0;
  PlayerHP = 100;
  PlayerGold = 0;
  PlayerAttack = 0;
  PlayerEqippedDamage = 0;
  PlayerEqippedDefense = 0;
  PlayerBlock = 3;
  P_outcomedamage = 0;
  E_outcomedamage = 0;
  turns = 0;
  PlayerAlive = true;
  PlayerWon = false;
  PlayerName = "";
  Location = "Home";
  Enemies.clear();
  Inventory.clear();

  // Enemy stats: ID, name, health, attack, block, gold, isAlive

  // Creating an Orc army
  Enemy en;
  for (int i = 0; i < 4; i++) {
    en = {i, "Orc", 100, 10, 3, 100, true};
    Enemies.push_back(en); // Add the orc to the list of enemies
  }
  // // Creating a chicken army
  // for (int i = Enemies.size(); i < Enemies.size() + 3; i++) {
  //   en = {i, "Chicken", 40, 3, 2, 5, true};
  //   Enemies.push_back(en);
  // }
}

// Check to see if a string is a number
bool checkIfANumber(string input) {
  return all_of(input.begin(), input.end(), ::isdigit);
}

// Prints out stats based on program input
void PrintStats(int input) {
  switch (input) {
  case 1:
    cout << "\nYour stats are:\n";
    cout << "HP: " << PlayerHP << "\n";
    cout << "Gold: " << PlayerGold << "\n";
    cout << "Attack: (random number(1-10) + equipment damage("
         << PlayerEqippedDamage << ")).\n";
    cout << "Block: " << PlayerBlock << "\n\n";
    break;
  case 2:
    cout << "\n" << Enemies[currentEnemy].name << " stats are:\n";
    cout << "ID: " << Enemies[currentEnemy].ID << "\n";
    cout << "HP: " << Enemies[currentEnemy].health << "\n";
    cout << "Attack: " << Enemies[currentEnemy].attack << "\n";
    cout << "Block: " << Enemies[currentEnemy].block << "\n";
    if (Enemies[currentEnemy].isAlive == false) {
      cout << Enemies[currentEnemy].name << " is dead!\n\n";
    } else {
      cout << Enemies[currentEnemy].name << " is alive!\n\n";
    }
    break;
  default:
    cout << "Invalid input.\n";
  }
}

// Prints out stats based on player input
void PrintStats() { // Prints the stats of the charecter.
  int input = 0;
  string in = "";
  do {
    cout << "\nSee stats of (You = 1, Current Enemy = 2): ";
    cin >> in;
    if (checkIfANumber(in)) {
      input = stoi(in);
    } else {
      cout << "Not a number.\n";
    }

    if (input != 1 && input != 2) {
      cout << "Invalid input.\n";
    }
  } while (input != 1 && input != 2);

  PrintStats(input);
}

// Prints out the player Location
void PrintLocation() {
  cout << "You are at the " << Location << " location.\n";
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

// Removes an item from the inventory
bool RemoveFromInventory(string item) {
  auto it = find_if(Inventory.begin(), Inventory.end(),
                    [&](const Item &i) { return i.name == item; });
  if (it != Inventory.end()) {
    Inventory.erase(it);
    cout << "You have removed " << item << " from your inventory.\n";
    return true;
  } else {
    cout << "You do not have " << item << " in your inventory.\n";
    return false;
  }
}

// Adds an item to the inventory
void AddToInventory(const string &itemName, bool isEquipped, int damage,
                    int defense) {
  Item newItem = {itemName, isEquipped, damage, defense};
  Inventory.push_back(newItem);
}

// Edits an iem in the inventory
void EditInventory(const string &itemName, bool isEquipped, int damage,
                   int defense) {
  auto it = find_if(Inventory.begin(), Inventory.end(),
                    [&](const Item &i) { return i.name == itemName; });
  if (it != Inventory.end()) {
    it->isEquipped = isEquipped;
    it->damage = damage;
    it->defense = defense;
  } else {
    cout << "You do not have " << itemName << " in your inventory.\n";
  }
}

// Equip an item from the inventory
void EquipItem(const string &itemName, bool isEquipped) {
  auto it = find_if(Inventory.begin(), Inventory.end(),
                    [&](const Item &i) { return i.name == itemName; });
  if (it != Inventory.end()) {
    it->isEquipped = isEquipped;
  }
  PlayerEqippedDamage = 0;
  PlayerEqippedDefense = 0;
  for (const auto &item : Inventory) {
    PlayerEqippedDamage += item.damage;
    PlayerEqippedDefense += item.defense;
  }
}

// Show the player inventroy
void ShowInventory() {
  if (Inventory.size() == 0) {
    cout << "You have no items in your inventory.\n";
    return;
  }
  cout << "You have the following items in your inventory: \n";
  for (const auto &item : Inventory) {
    cout << "- " << item.name << "\n";
    cout << "  Damage: " << item.damage << "\n";
    cout << "  Defense: " << item.defense << "\n";
    cout << "  Equipped: " << (item.isEquipped ? "Yes" : "No") << "\n";
  }
}

// Manages the invintory. Players can add items to their inventory, remove items
// from their inventory, and equip items.
void InventoryF() {
  int inputInt = 0;
  string input = "";

  do {
    cout << "Do you want to (view = 1, remove = 2, equip = 3): ";
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
    ShowInventory();
    break;
  case 2: // remove
    if (Inventory.size() == 0) {
      cout << "You have nothing in your inventory.\n";
      break;
    }
    while (itemvalid) {
      cout << "What do you want to remove from your inventory? (q = cancel)\n";
      cin >> input;
      if (input == "q") {
        itemvalid = true;
        break;
      }
      itemvalid = RemoveFromInventory(input);
    }
    break;
  case 3: // equip
    if (Inventory.size() == 0) {
      cout << "You have nothing in your inventory.\n";
      break;
    }
    ShowInventory();
    while (itemvalid) {
      cout << "What do you want to equip? (q = cancel)\n";
      cin >> input;
      if (input == "q") {
        break;
      }

      EditInventory(input, true, 0, 0);
    }

  default:
    cout << "Invalid input.\n";
    break;
  }
}

// Asks the player what actions they want to take such as see stats, see
// inventory, etc.
bool ActionQuestion(string question) {
  if (!AskYesNo("Skip action? ")) {
    do {
      if (AskYesNo("Do you want to see stats? ")) {
        PrintStats();
      } else {
        break;
      }
    } while (true);
    do {
      if (AskYesNo("Do you want to interact with Invintory? ")) {
        InventoryF();
      } else {
        break;
      }
    } while (true);
    do {
      if (AskYesNo("Do you want to see your location? ")) {
        PrintLocation();
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

// Rolls a die with the set number of sides
int diceRoll() { return rand() % 6 + 1; }

// Rolls a random number between 1 and the number of sides the player set
int AdvancedDiceRoll() {
  int sides;
  cout << "How many sides on the die? ";
  cin >> sides;
  if (sides < 2) {
    sides = 2;
    cout << "Must be at least 2 sides!\n";
  }
  if (sides > 100) {
    sides = 100;
    cout << "Must be at most 100 sides!\n";
  }
  return rand() % sides + 1;
}

// Rolls a random number between 1 and the number of sides the progam set
int AdvancedDiceRoll(int sides) { return rand() % sides + 1; }

void SetCurrentEnemy(int enemy) {
  for (const auto &en : Enemies) {
    if (en.ID == enemy) {
      currentEnemy = en.ID;
      return; // found
    }
  }
  cout << enemy << "not found.\n";
}

// Initiates a fight bewteen the player and the enemy
void Fight() {
  turns++; // Increases the number of turns the player has played.

  // Player attacks the current enemy
  PlayerAttack = AdvancedDiceRoll(10) + PlayerEqippedDamage;
  cout << "You attack for " << PlayerAttack << " damage!\n";
  cout << "The " << Enemies[currentEnemy].name << " blocks for "
       << Enemies[currentEnemy].block << " damage!\n";
  P_outcomedamage = PlayerAttack - Enemies[currentEnemy].block;
  if (P_outcomedamage > 0) {
    Enemies[currentEnemy].health =
        Enemies[currentEnemy].health - P_outcomedamage;
  } else {
    cout << "The " << Enemies[currentEnemy].name << " blocked the attack!\n";
  }

  // Displays the enemys health
  cout << "\nThe " << Enemies[currentEnemy].name << " has "
       << Enemies[currentEnemy].health << " health left!\n\n";

  // check if the enemy is dead
  if (Enemies[currentEnemy].health <= 0) {
    Enemies[currentEnemy].isAlive = false;
    cout << "The " << Enemies[currentEnemy].name << " is dead!\n";
    PlayerGold += Enemies[currentEnemy].gold;
    cout << "You search the " << Enemies[currentEnemy].name
         << " corpse and find " << Enemies[currentEnemy].gold << " gold!\n";
    PlayerWon = true;
  }

  // Enemy attacks the player
  if (Enemies[currentEnemy].health > 0) {
    Enemies[currentEnemy].attack = AdvancedDiceRoll(10);
    cout << "The " << Enemies[currentEnemy].name << " attacks for "
         << Enemies[currentEnemy].attack << " damage!\n";
    cout << "You blocked " << (PlayerBlock + PlayerEqippedDefense)
         << " damage!\n";
    E_outcomedamage =
        Enemies[currentEnemy].attack - (PlayerBlock + PlayerEqippedDefense);
    if (E_outcomedamage > 0) {
      PlayerHP = PlayerHP - E_outcomedamage;
    } else {
      cout << "You blocked the attack!\n";
    }
  }

  // Displays the players health
  cout << "\nYou have " << PlayerHP << " health left!\n\n";

  // Check if the player won the fight
  if (P_outcomedamage - E_outcomedamage > 0) {
    cout << "You won the fight!\n";
    int goldFound = AdvancedDiceRoll(5);
    PlayerGold = PlayerGold + goldFound;
    cout << "You found " << goldFound << " gold!\n";
  } else {
    cout << "You lost the fight!\n";
  }
  // Check if the player needs to go to doc
  if (PlayerHP < 5) {
    string spend = "";
    int amount = 0;
    bool isValidNum = false;
    if (AskYesNo("Do you want to go to the doctor? ")) {
      cout << "You go to the doctor and he heals you equal to the gold you "
              "spend.\n";
      cout << "You have " << PlayerGold << " gold left.\n";
      if (PlayerGold > 0) {
        if (AskYesNo("Do you want to spend gold? ")) {
          do {
            cout << "\nHow much do you want to spend? ";
            cin >> spend;
            if (checkIfANumber(spend)) {
              amount = stoi(spend);
              if (amount > PlayerGold) {
                cout << "You don't have that much gold!\n";
              } else {
                cout << "You spend " << amount << " gold.\n";
                PlayerGold = PlayerGold - amount;
                PlayerHP = PlayerHP + amount;
                cout << "You now have " << PlayerGold << " gold left.\n";
                cout << "You now have " << PlayerHP << " health left.\n";
                isValidNum = true;
              }
            }
          } while (!isValidNum);
          isValidNum = false;
        }
      }
    }
    PrintStats(1);
  }

  // Check if the player is dead
  if (PlayerHP <= 0) {
    PlayerAlive = false;
    PlayerWon = false;
    cout << "You died!\n";
    cout << "You collected " << PlayerGold << " gold!\n";
    cout << "You lasted " << turns << " turns!\n";
    cout << "You lost the game!\n\n\n";
  } else {
    cout << "Player escaped with " << PlayerGold << " gold!\n";
  }
  return;
}

int Adventure() {

  // Set the sceen and the player's stats.
  cout << "What is your name? ";
  cin >> PlayerName;
  cout << "\nWelcome " << PlayerName << "!\n\n";
  PrintStats(1);
  cout << "\nYou live in a house in a dark forest.\n";

  if (ActionQuestion("Would you like to go on an adventure? ")) {
    cout << "\nYou go on an adventure!\n";
    cout << "You come across a fork in the road.\n";
    Location = "Fork in the road";
    if (AskYesNo("Do you go left? ")) {
      cout << "\nYou go left.\n";
      Location = "Left";
      if (!ActionQuestion("Do you go down the hill? ")) {
        cout << "\nYou go into the brush and find a club.\n";
        Location = "Hill";
        if (AskYesNo("Do you take it? ")) {
          AddToInventory("club", false, 5, 0);
          cout << "\nYou take the club.\n";
          if (AskYesNo("Do you want to equip the club? ")) {
            EquipItem("club", true);
            cout << "\nYou equip the club.\n";
            cout << "Your attack is now (1-10) + " << PlayerEqippedDamage
                 << ".\n";
          }
        }
        cout << "\nYou contiue on your journey.\n";
      }
      cout << "You go down the hill.\n\n";
      Location = "Down Hill";
      if (ActionQuestion("Do you go through the forest? ")) {
        cout << "\nYou go through the forest.\n";
        Location = "Forest";
        cout << "You find a house.\n";
        if (ActionQuestion("Do you go in? ")) {
          cout << "\nYou go in the house.\n";
          Location = "Forest House";
          cout << "You find a treasure chest!\n";
          if (AskYesNo("Do you open it? ")) {
            cout << "\nYou open the chest.\n";
            cout << "You find a sword!\n";
            if (AskYesNo("Do you take it? ")) {
              cout << "\nYou take the sword.\n";
              if (AskYesNo("Do you want to equip the sword? ")) {
                EquipItem("sword", true);
                cout << "\nYou equip the sword.\n";
                cout << "Your attack is now (1-10) + " << PlayerEqippedDamage
                     << ".\n";
              }
            }
          }
        }
      }
      cout << "You go back to the fork in the road.\n";
      Location = "Fork in the road";
      cout << "You go right.\n";
      Location = "Right";
      SetCurrentEnemy(0); // Orc
      cout << "You have encountered a " << Enemies[currentEnemy].name << "!\n";
      Fight();
    } else {
      cout << "\nYou go right.\n";
      Location = "Right";
      SetCurrentEnemy(0); // Orc
      cout << "You have encountered a " << Enemies[currentEnemy].name << "!\n";
      Fight();
    }
  } else {
    cout << "\nYou go to sleep.\n";
    cout << "You wake up.\n";
    SetCurrentEnemy(0); // Orc
    cout << "You run into an " << Enemies[currentEnemy].name
         << " at the door!\n\n";
    Fight();
  }

  // Ask if player wants to fight the Enmey again
  do {
    if (AskYesNo("Would you like to Fight the " + Enemies[currentEnemy].name +
                 " again? ")) {
      cout << "\n";
      Fight();
      if (!Enemies[currentEnemy].isAlive || !PlayerAlive) {
        break;
      }
    } else {
      break;
    }
  } while (true); // Keep fighting until player says no

  // After the enemy is dead, or player dies, or player runs away, check end
  // conditions
  if (PlayerAlive && PlayerWon) {
    return 1;
  }
  if (PlayerAlive) {
    return 2;
  } else {
    return 3;
  }
}

void StartAdventure() {
  int AdOutcome = Adventure(); // Start the adventure
  cout << "\n\n\nYou went on an adventure and this is what happened: \n";
  switch (AdOutcome) {
  case 1:
    cout << "You won!\n\nYou mastered " + to_string(turns) +
                " turns.\nYou found " + to_string(PlayerGold) + " gold.\n" +
                PlayerName + " is a hero!\n" + "You are a legend!\n";
    break;
  case 2:
    cout << "You ran away!\n\nYou lasted " + to_string(turns) + " turns.\n" +
                "You found " + to_string(PlayerGold) + " gold.\n" + PlayerName +
                " is a coward!\n" + "You are a coward!\n";
    break;
  case 3:
    cout << "You died!\n\nYou lasted " + to_string(turns) + " turns.\n";
    break;
  default:
    cout << "Something went wrong!\n";
    break;
  }
  PrintStats(1);
  ShowInventory();
  cout << "\n";

  // Get total enemies
  int totalEnemies = 0;
  for (const auto &en : Enemies) {
    if (en.isAlive) {
      totalEnemies++;
    }
  }
  cout << "Enemies left: " << totalEnemies << "\n";

  // Display every enemies stats that are still alive
  for (const auto &en : Enemies) {
    if (en.isAlive) {
      currentEnemy = en.ID;
      PrintStats(2);
    }
  }
  cout << "\n\n";
}

int main() {
  srand(time(0)); // seed the random number generator
  cout << "Welcome to the Adventure Game!\n\n";

  RestartGame();

  StartAdventure();

  while (true) {
    if (AskYesNo("Want to try again?")) {
      cout << "Came back for more ehhh?\n";
      RestartGame();
      StartAdventure();
    } else {
      break;
    }
  }
  cout << "Wow reallly?!?!?!?!?!?!?!?!?!?!?!?!\n";
  cout << "You are so boring!\n";
  cout << "I'm done with you!\n";
  return 0;
}