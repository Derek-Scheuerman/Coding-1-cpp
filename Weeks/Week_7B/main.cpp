#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int tripled(int x) {
  if (x == 69) {
    return 696969;
  }
  return x * 3;
}

void DisplayVec(vector<string> vec) {
  cout << "\nDisplaying " << vec[0] << ": " << endl;
  for (int i = 1; i < vec.size(); i++) {
    cout << vec[i] << endl;
  }
  cout << "\n\n";
}

void editInv(vector<string> &Inv, int action, string item) {
  switch (action) {
  // Add item
  case 1:
    Inv.push_back(item);
    break;
  // Remove item
  case 2:
    for (int i = 0; i < Inv.size(); i++) {
      if (Inv[i] == item) {
        Inv.erase(Inv.begin() + i);
      }
    }
    break;
  // View inv
  case 3:
    DisplayVec(Inv);
    break;
  // Change item
  case 4:
    string itemName;
    cout << "What would you like to change " << item << " to?\n";
    cin >> itemName;
    for (int i = 0; i < Inv.size(); i++) {
      if (Inv[i] == item) {
        Inv[i] = itemName;
        break;
      }
    }
    break;
  }
}

int main() {
  int input;
  cout << "Triple of 3 is: " << tripled(3) << endl;
  cout << "Triple of 5 is: " << tripled(5) << endl;
  cout << "Pick a number: ";
  cin >> input;
  cout << "Triple of " << input << " is: " << tripled(input) << endl;

  vector<string> colors = {"Colors", "red",  "orange", "yellow",
                           "green",  "blue", "indigo", "violet"};
  DisplayVec(colors);

  vector<string> inv = {"Invintory", "sword", "shield", "armor"};
  DisplayVec(inv);
  while (true) {
    int inputAction = 0;
    string inputItem = "";
    cout << "What would you like to do?\n"
            "(1 = add item to inv, 2 = Remove item, 3 = Display,\n"
            "4 = Change Item, 5 quit)\n";
    cin >> inputAction;
    if (inputAction == 5) {
      break;
    } else if (inputAction == 1) {
      cout << "What would you like to add?\n";
      cout << "Item name: ";
      cin >> inputItem;
    } else if (inputAction == 2) {
      cout << "What would you like to remove?\n";
      cout << "Item name: ";
      cin >> inputItem;
    } else if (inputAction == 4) {
      cout << "What would you like to change?\n";
      cout << "Item name: ";
      cin >> inputItem;
    }
    editInv(inv, inputAction, inputItem);
  }

  map<string, string> userpass;
  userpass["user1"] = "pass1";
  userpass["Derek"] = "password";
  string username, password;
  while (true) {
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    if (userpass.find(username) != userpass.end()) {
      if (userpass[username] == password) {
        cout << "Access granted" << endl;
        cout << "Login successful!" << endl;
        break;
      } else {
        cout << "Incorrect password" << endl;
      }
    } else {
      cout << "Invalid username" << endl;
    }
  }
}