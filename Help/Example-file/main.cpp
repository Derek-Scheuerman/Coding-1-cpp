#include "main.h"

int main() {

  // Load games from the file into our vector
  FileInteractions fileInteractions; // Create an instance of FileInteractions

  fileInteractions.load(favGames, fileName); // Call the load function using the
                                             // instance of FileInteractions

  cout << "Here are your favorite games imported from file:\n";
  showGames();
  // add a game and show it
  addGame();
  showGames();

  // save games to file
  fileInteractions.save(favGames, fileName);
}

void addGame() {
  string game;
  cout << "What game would you like to add?\n";
  getline(cin, game);
  favGames.push_back(game);
}

void showGames() {
  cout << "\n\nHere are your fav games:\n";
  for (int game = 0; game < favGames.size(); game++) {
    cout << favGames[game] << endl;
  }
}

void removeGame() {
  string gameToRemove;
  cout << "What game would you like to remove?\n";
  getline(cin, gameToRemove);

  // Go through each game in the vector and see if it matches the game to remove
  for (int gameNum = 0; gameNum < favGames.size(); gameNum++) {
    if (favGames[gameNum] == gameToRemove) {
      // If it does, erase the game from the vector
      favGames.erase(favGames.begin() + gameNum);
      cout << "Game removed.\n";
      return;
    }
  }
  cout << "Game not found.\n";
}

void editGame() {
  string gameToEdit;
  cout << "What game would you like to edit?\n";
  getline(cin, gameToEdit);
  for (int gameNum = 0; gameNum < favGames.size(); gameNum++) {
    if (favGames[gameNum] == gameToEdit) {
      cout << "What would you like to change " << favGames[gameNum] << " to?\n";
      getline(cin, favGames[gameNum]);
      cout << "Game edited.\n";
      return;
    }
  }
  cout << "Game not found.\n";
}

void clearGames() {
  cout << "\n\nClearing games...\n";
  favGames.clear();
}