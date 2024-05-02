#include "main.h"

/*Create a program that will accept the user's fav games.

On quit of application, save those games to file.

On Open, load those games from file.

Use Getline().

Use a Vector<string>.

Use a header file for the load() and save()
functions.

Load will add the favgames from the .txt file to the vector.

Save will write the favgames from the vector to the file.

The user should be able to Add a favGame, Edit a favGame, Show the favGames, and
Clear the list of favGames.*/

int main() {

  FileInteractions fileInteractions; // Create an instance of FileInteractions
  bool quit = false;
  /*fileInteractions.load(favGames, fileName); // Call the load function using
  the
                                             // instance of FileInteractions

  while (!quit) {
    quit = optionMenu();
  }
  fileInteractions.save(favGames, fileName);

  clearGames();*/
  cout << "Entering the encripted file" << endl;
  fileInteractions.encriptedLoad(favGames, encriptedFileName, primes, key);
  quit = false;
  while (!quit) {
    quit = optionMenu();
  }
  fileInteractions.encriptedSave(favGames, encriptedFileName, primes, key);
}

bool optionMenu() {
  int option = 0;
  string input = "";
  cout << "\n\nWhat would you like to do?" << endl;
  cout << "1. Add a game" << endl;
  cout << "2. remove a game" << endl;
  cout << "3. Edit a game" << endl;
  cout << "4. Show the games" << endl;
  cout << "5. Clear the games" << endl;
  cout << "6. Quit" << endl;
  cout << "Enter your choice: ";
  getline(cin, input);
  option = stoi(input);
  switch (option) {
  case 1:
    addGame();
    break;
  case 2:
    removeGame();
    break;
  case 3:
    editGame();
    break;
  case 4:
    showGames();
    break;
  case 5:
    clearGames();
    break;
  case 6:
    cout << "Thank you for using my program!" << endl;
    return true;
    break;
  default:
    cout << "Invalid option. Please try again." << endl;
    break;
  }
  return false;
}

void addGame() {
  string favGame;
  cout << "What game would you like to add?\n";
  getline(cin, favGame);
  favGames.push_back(favGame);
}
void showGames() {
  cout << "\n\nHere are your fav games:\n";
  for (int i = 0; i < favGames.size(); i++) {
    cout << favGames[i] << endl;
  }
}
void removeGame() {
  string favGame;
  cout << "What game would you like to remove?\n";
  getline(cin, favGame);
  for (int i = 0; i < favGames.size(); i++) {
    if (favGames[i] == favGame) {
      favGames.erase(favGames.begin() + i);
      cout << "Game removed.\n";
    } else {
      cout << "Game not found.\n";
    }
  }
}

void editGame() {
  string favGame;
  bool found = false;
  cout << "What game would you like to edit?\n";
  getline(cin, favGame);
  for (int i = 0; i < favGames.size(); i++) {
    if (favGames[i] == favGame) {
      cout << "What would you like to change " << favGame << " to?\n";
      getline(cin, favGame);
      favGames[i] = favGame;
      cout << "Game edited.\n";
      found = true;
      break;
    }
  }
  if (!found) {
    cout << "Game not found.\n";
    cout << "Would you like to add " << favGame << " to your list? (y/n)\n";
    string choice;
    cin >> choice;
    if (choice == "y") {
      favGames.push_back(favGame);
      cout << "Game added.\n";
    } else {
      cout << "Game not added.\n";
    }
    cout << "Would you like to try again?\n";
    cin >> choice;
    if (choice == "y") {
      editGame();
    }
  }
}
void clearGames() {
  favGames.clear();
  cout << "All games cleared.\n";
}