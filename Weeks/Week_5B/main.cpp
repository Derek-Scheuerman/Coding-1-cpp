#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

string AddInvItem() {
  string item;
  cout << "Enter the name of the item you want to add: ";
  cin >> item;
  return item;
}
string removeItem() {
  string item;
  cout << "Enter the name of the item you want to remove: ";
  cin >> item;
  return item;
}
void ShowInv(vector<string> inv) {
  cout << "Your inventory contains: " << endl;
  for (int i = 0; i < inv.size(); i++) {
    cout << inv[i] << "\n";
  }
}

void InvintoryP() {
  cout << "\nLet's create an invintory!\n\n";
  // A vector is a list of items that you can change the size of.
  vector<string> invintory; // Default size of 0
  invintory.push_back("Sword");
  invintory.push_back("Shield");
  invintory.push_back("Armor");
  invintory.push_back("Snack");
  invintory.push_back("Potion");
  invintory.push_back("Bow");
  cout << "There are " << invintory.size()
       << " items in your invintory.\n\n";
  cout << "Your invintory:\n";
  for (int i = 0; i < invintory.size(); i++) {
    cout << invintory[i] << "\n";
  }
  bool state = true;
  while (state) {
    int input;
    cout << "What do you want to do with the invintory? (add = 1, remove = 2, show = 3, quit = 4)\n";
    cin >> input;
    switch (input) {
    case 1:
      invintory.push_back(AddInvItem());
      break;
    case 2: {
      string item = removeItem();
      for (int i = 0; i < invintory.size(); i++) {
        if (invintory[i] == item) {
          invintory.erase(invintory.begin() + i);
        }
      }
      break;
    }
    case 3:
      ShowInv(invintory);
      break;
    case 4:
      cout << "Goodbye!";
      state = false;
      break;
    default:
      cout << "Invalid input.\n";
      break;
    }
  }
}
void IteratorP() {
  cout << "Let's talk about iterators!\n";
  vector<string> friends{"Derek", "Josh", "James", "Jack"};
  cout << "There are " << friends.size() << " friends.\n";

  cout << "The first friend is " << *friends.begin()
       << " and the last friend is " << *(friends.end() - 1) << ".\n";

  // Using a constant iteratir in a for loop.
  for (vector<string>::iterator iter = friends.begin(); iter != friends.end();
       iter++) {
    cout << *iter << endl;
    // interators are like pointers, but they are read only.
    // You can't change the value of the iterator.
  }
}
void AlgorithemsP() {
  srand(time(0));
  
    cout << "Let's talk about algorithms!\n";
  vector<int> scores;
  for (int i = 0; i < 10; i++) {
    scores.push_back(rand() % 100 + 1);
  }
    
  for (vector<int>::iterator iter = scores.begin(); iter != scores.end();
       iter++) {
    cout << *iter << endl;
  }

    
  sort(scores.begin(), scores.end());
  cout << "Sorted scores:\n";
  for (vector<int>::iterator iter = scores.begin(); iter != scores.end();
       iter++) {
    cout << *iter << endl;
  }
    
  reverse(scores.begin(), scores.end());
  cout << "Reversed scores:\n";
  for (vector<int>::iterator iter = scores.begin(); iter != scores.end();
       iter++) {
    cout << *iter << endl;
  }
    
  random_shuffle(scores.begin(), scores.end());
    cout << "Shuffled scores:\n";
  for (vector<int>::iterator iter = scores.begin(); iter != scores.end();
       iter++) {
    cout << *iter << endl;
  }
    
  int input = 0;
  while (input != -1 && scores.size() > 0) {
    cout << "The numbers:\n";
    for (int i = 0; i < scores.size(); i++) {
      cout << scores[i] << endl;
    }

    cout << "What number do you want to remove?\n";
    cin >> input;

    vector<int>::iterator iter = find(scores.begin(), scores.end(), input);
    if (iter != scores.end()) {
      scores.erase(iter);
    } else {
      cout << "I couldn't find that number, sorry.\n";
    }
  }
}
int main() {
  cout << "What would you like to do?\n";
  cout << "Press 1 to run the Invintory program.\n";
  cout << "Press 2 to run the Itorator program.\n";
  cout << "Press 3 to run the Algortihm program.\n";
  int select = 0;
  cin >> select;
  if (select == 1) {
    InvintoryP();
  } else if (select == 2) {
    IteratorP();
  } else if (select == 3) {
    AlgorithemsP();
  } else {
    cout << select << " is not a valid option.\n";
  }
  return 0;
}