
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class robot {
  // Data members (variables)
private:
  string name;
  int charge;
  int id;

public:
  // member functions
  void status() {
    cout << "\n[id: " << id << ", name: " << name << ", charge: " << charge
         << "%]\n";
  }

  // A constructor is a special member function that runs when a new object is
  // created. It is used to initialize the data members of a class. It always
  // has the same name as the class and has no return type.
  robot(string givenName = "Robot", int givenCharge = 10, int ID = 0) {
    name = givenName;
    charge = givenCharge;
    id = ID;
  }

  // Getters
  string getName() { return name; }
  int getCharge() { return charge; }
  int getID() { return id; }
  // Setters
  void setName(string givenName) {
    if (givenName.size() < 15) {
      name = givenName;
    } else {
      cout << "Name is too long!\nMust be less than 15 characters.\n";
    }
  }
  void setCharge(int givenCharge) {
    if (givenCharge < 0) {
      cout << "Charge cannot be negative!\n";
      charge = 0;
      cout << "Charge is now 0.\n";
    } else {
      charge = givenCharge;
    }
  }
  void setID(int givenID) { id = givenID; }
};

int main() {
  srand(time(0));
  cout << "Let's build some classes!\n";
  // create a new variable of type "robot" named "Robbie"
  robot rob;
  rob.setName("Robbie");
  rob.setCharge(rand() % 5 + 5);

  cout << "\nMy robots name is " << rob.getName() << ".\n";
  cout << rob.getName() << " has " << rob.getCharge() << "% charge.\n";
  rob.status();

  robot threepio("Threepio", rand() % 6 + 5);
  threepio.status();

  robot sad;
  sad.status();

  cout << "\nCreating a vector of robots!\n\n";

  vector<robot> bots;
  vector<string> names = {"Bob", "Jerry", "Tom", "Jimmy", "Timmy", "Sally"};

  for (int i = 0; i < 10; i++) {
    bots.push_back(robot(names[rand() % names.size()], rand() % 80 + 5, i));
  }

  for (int i = 0; i < bots.size(); i++) {
    bots[i].status();
  }
}