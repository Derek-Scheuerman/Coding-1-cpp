#include "../includes.h"

class Robot {
private:
  string name;
  int charge;

public:
  Robot(string name, int charge) : name(name), charge(charge){};

  string getName() { return name; }
  int getCharge() { return charge; }
  void setName(string name) { this->name = name; }
  void setCharge(int charge) { this->charge = charge; }
  void Status() {
    cout << "Im a robot named " << name << " and my charge is " << charge
         << endl;
  }
};