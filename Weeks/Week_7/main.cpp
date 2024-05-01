#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// return type, name, (input), { code }
void SayHello() {
  cout << "Hello World!"
       << "\n\n";
}

void Say(string input) { cout << input << "\n\n"; }

int AddTwoNumbers(int num1, int num2) {
  int sum = num1 + num2;
  return sum;
}

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

int diceRoll() { return rand() % 6 + 1; }

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

int castDamage(int min, int max, int numHits, string entity, int HP) {
  int EnemyHP = HP;
  for (int i = 0; i < numHits; i++) {
    cout << entity << " is casting damage... \n(between " << min << "-" << max
         << " with chance of crit)\n";
    int damage = rand() % (max - min + 1) + min;
    int crit = diceRoll();
    if (crit == 6) {
      damage *= 2;
      cout << "Critical hit!\n";
    }
    cout << entity << " did " << damage << " damage!\n\n";
    EnemyHP -= damage;
  }
  return EnemyHP;
}

int main() {
  srand(time(0)); // seed the random number generator
  SayHello();     // call the function
  Say("How are you today?");
  Say("Non o yo bezwax!");
  if (AskYesNo("Do you like cats?")) {
    cout << "You like cats!\n\n";
  } else {
    cout << "You don't like cats!\n\n";
  }

  cout << "do you want to roll normal dice or advanced dice? (n/a) ";
  string input;
  cin >> input;
  if (input == "n") {
    cout << "You rolled a " << diceRoll() << "!\n\n";
  } else if (input == "a") {
    int advroll = AdvancedDiceRoll();
    cout << "You rolled a " << advroll << "!\n\n";
  }

  int playerHP = 100;
  int slimeHP = 50;
  while (playerHP > 0 && slimeHP > 0) {
    slimeHP = castDamage(1, 10, 2, "Player", slimeHP);
    playerHP = castDamage(5, 7, 3, "Slime", playerHP);
    cout << "You have " << playerHP << " HP.\n";
    cout << "The slime has " << slimeHP << " HP.\n\n";
  }
  cout << "5 + 7 = " << AddTwoNumbers(5, 7) << ".\n\n";
  vector<string> LeastFavFoods = {"Worms", "Bugs", "Catfish", "fig",
                                  "Cooked Spinach"};
  cout << "Least Favorite Foods:" << endl;
  for (int i = 0; i < LeastFavFoods.size(); i++) {
    cout << LeastFavFoods[i] << endl;
  }
  return 0;
}