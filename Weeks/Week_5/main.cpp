#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  srand(time(0));
  string name = "Derek";
  string input = "";
  std::cout << "Hello " << name << "!\n";

  int counter = 0;
  while (counter++) {
    cout << "Counter = " << counter << ".\n";
  } // a while loop tests at the top of the loop and runs untill the test
    // evaluates to false.

  // while(input != "no") {
  //     cout << "Do want to keep adventuring?\n";
  //     cin >> input;
  // }
  do {
    cout << "Do you want to keep adventuring? (yes/no)\n";
    getline(cin, input);
  } while (input != "no"); // a do-while loop tests at the bottom of the loop
                           // and will always run at least once.

  while (true) {
    string response = "";
    cout << "Are we there yet? (yes/no)\n";
    getline(cin, response);
    if (response == "yes") {
      break;
    }
  }

  // A for loop has a counter built into the loop. It is best when you ned to
  // walk through a list of items. because it has a built in counter
  for (int i = 0; i < 10; i += 1) {
    cout << "i = " << i << ".\n";
  }
  vector<string> names{"Derek", "Juan", "Fred", "Bob", "Jack"};
  vector<int> scores = {4, 2, 5, 4, 5};

  for (int i = 0; i < 5; i += 1) {
    cout << names[i] << " has a score of " << scores[i] << ".\n";
  }
  cout << "\n\n";
  string test[5]{"", "", "", "", ""};
  int f = 0;
  bool skip = false;
  string randomname = "";

  while (true) {
    randomname = names[rand() % 5];
    cout << "Random name = " << randomname << "\n";
    for (int i = 0; i < 5; i++) {
      if (randomname == test[i]) {
        skip = true;
      }
    }
    if (skip) {
      skip = false;
    } else {
      test[f] = randomname;
      f += 1;
    }
    if (f == 5) {
      break;
    }
  }

  cout << "\n\n";
  for (int i = 0; i < 5; i += 1) {
    cout << test[i] << " scored " << scores[i] << ".\n";
  }
  cout << "\n\n";
  vector<string> favGames;
  while (true) {
    cout << "\nWhat would you like to do? (add/show/remove/quit)\n";
    string input;
    getline(cin, input);

    if (input == "add") {
      cout << "What game would you like to add?\n";
      getline(cin, input);
      favGames.push_back(input);
    } else if (input == "remove") {
      string item;
      cout << "Enter the name of the item you want to remove: ";
      cin >> item;
      vector<string>::iterator iter = find(favGames.begin(), favGames.end(), item);
      if (iter != favGames.end()) {
            favGames.erase(iter);
      } else {
        cout << "I couldn't find that number, sorry.\n";
      }
    } else if (input == "show") {
      cout << "\nHere are your favorite games:\n";
      for (int i = 0; i < favGames.size(); i += 1) {
        cout << favGames[i] << "\n";
      }
    } else if (input == "quit") {
      cout << "Thanks for playing!\n";
      break;
    }
  }
}