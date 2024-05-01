#include <cstdlib> // Includes the necessary library for random number generation
#include <ctime> // Includes the necessary library to seed the random number generator
#include <iostream> // Includes classes like cin for input and cout for output.
#include <string> // This library offers a set of classes and functions to work with strings
#include <vector> // Vectors offer member functions like push_back, pop_back

#include <algorithm> // Includes the necessary library for sorting.
#include <cmath> // Includes the necessary library for mathematical operations.
using namespace std;

// Strings are a sequence of characters, and they are enclosed in double quotes.
// Its a class that is defined in the string library.

// A function is a block of code that performs a specific task.
// A function can be called from anywhere in the program.
// A function can be called multiple times.
// A function can be called with different parameters.
// A function can return a value.
// A function can return multiple values.
// A function is defined using the following syntax:
// return_type function_name(parameter_list)

class dogs {
private:
  string name;
  int age;
  string breed;
  string color;
  int hungerLevel;
  int happinessLevel;
  int energyLevel;

public:
  dogs(string n, int a, string b, string c)
      : name(n), age(a), breed(b), color(c), hungerLevel(50),
        happinessLevel(50), energyLevel(50) {}
  void feed() {
    hungerLevel += 10;
    happinessLevel += 5;
    energyLevel += 5;
  }
  void play() {
    hungerLevel -= 10;
    happinessLevel += 15;
    energyLevel -= 10;
  }
  void sleep() {
    hungerLevel -= 5;
    happinessLevel += 10;
    energyLevel += 20;
  }
  void displayStatus() {
    cout << "Name: " << name << endl;
    cout << "Hunger Level: " << hungerLevel << endl;
    cout << "Happiness Level: " << happinessLevel << endl;
    cout << "Energy Level: " << energyLevel << endl;
  }
  void displaypet() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Breed: " << breed << endl;
    cout << "Color: " << color << endl;
    cout << "Hunger Level: " << hungerLevel << endl;
    cout << "Happiness Level: " << happinessLevel << endl;
    cout << "Energy Level: " << energyLevel << endl;
  }
  string getName() const { return name; }
  int getAge() const { return age; }
  string getBreed() const { return breed; }
  string getColor() const { return color; }
  int getHungerLevel() const { return hungerLevel; }
  int getHappinessLevel() const { return happinessLevel; }
  int getEnergyLevel() const { return energyLevel; }

  void rename(string newName) { name = newName; }
  void changeBreed(string newbreed) { breed = newbreed; }
  void changeColor(string newcolor) { color = newcolor; }
  void changeAge(int newage) { age = newage; }
  void increaseAge() { age++; }
  void drainHunger() { hungerLevel -= 10; }
  void bark() {
    cout << "Woof!" << endl;
    if (hungerLevel < 50) {
      cout << "I'm hungry!" << endl;
    } else if (hungerLevel < 30) {
      cout << "I'm starving!" << endl;
    }
    if (happinessLevel < 50) {
      cout << "I'm sad!" << endl;
    } else if (happinessLevel < 30) {
      cout << "I'm depressed!" << endl;
    }
    if (energyLevel < 50) {
      cout << "I'm tired!" << endl;
    } else if (energyLevel < 30) {
      cout << "I'm exhausted!" << endl;
    }
  }
};

// Player lol
class basketCase {
private:
  string name;
  int price;
  int quantity;
  int rgb[3];
  vector<dogs> Collection;

public:
  basketCase(string n, int p, int q, int r, int g, int b)
      : name(n), price(p), quantity(q), rgb{r, g, b} {}
  string getName() { return name; }
  int getPrice() { return price; }
  int getQuantity() { return quantity; }
  int getRgb(int index) { return rgb[index]; }
  int getRgb() { return *rgb; }
  void addDog(dogs d) { Collection.push_back(d); }
  bool removeDog(string dogName) {
    auto it = find_if(Collection.begin(), Collection.end(),
                      [&](const dogs &i) { return i.getName() == dogName; });
    if (it != Collection.end()) {
      Collection.erase(it);
      cout << "You have removed " << dogName << " from your Collection.\n";
      return true;
    } else {
      cout << "You do not have " << dogName << " in your Collection.\n";
      return false;
    }
  }
  void displayCollection() {
    for (int i = 0; i < Collection.size(); i++) {
      Collection[i].displaypet();
    }
  }
  void setName(string n) { name = n; }
  void setPrice(int p) { price = p; }
  void setQuantity(int q) { quantity = q; }
  void setRgb(int r, int g, int b) {
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;
  }
};

// Check to see if a string is a number
bool checkIfANumber(string input) {
  return all_of(input.begin(), input.end(), ::isdigit);
}
void displayTitle() {
  cout << "__        __   _                            _         " << endl;
  cout << "\\ \\      / /__| | ___ ___  _ __ ___   ___  | |_ ___   " << endl;
  cout << " \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  "
       << endl;
  cout << "  \\ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) | " << endl;
  cout << "   \\_/\\_/_\\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/  "
       << endl;
  cout << "      |  _ \\  ___   __ \\ \\   / (_) | | ___    " << endl;
  cout << "      | | | |/ _ \\ / _` \\ \\ / /| | | |/ _ \\   " << endl;
  cout << "      | |_| | (_) | (_| |\\ V / | | | |  __/  " << endl;
  cout << "      |____/ \\___/ \\__, | \\_/  |_|_|_|\\___|  " << endl;
  cout << "                   |___/\n\n";
}

void IneractWithDog() {
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

int main() {
  cout << "Hello World!\n";
  cout << "Welcome to the game!\n";
  displayTitle();
  cout << "You are a dog owner!\n";
  cout << "You are a basket case with a limited space!\n";
  cout << "You can add dogs to your collection!\n";
  cout << "You can also remove dogs from your basket case collection!\n\n";

  while (true) {
    cout << "What would you like to do?\n";
    cout << "1. Add a dog to your collection.\n";
    cout << "2. Remove a dog from your collection.\n";
    cout << "3. Display your collection.\n";
    cout << "4. Interact with a dog in your collection.\n";
    cout << "4. Exit\n";
    break;
  }
}