#include "fileInteractions.h"

FileInteractions::FileInteractions() {}

// Loads the file into the vector
void FileInteractions::load(vector<string> &favGames, string &fileName) {
  ifstream file;
  file.open(fileName);
  string game;
  while (getline(file, game)) {
    favGames.push_back(game);
  }
  file.close();
}

// Saves the vector to the file
void FileInteractions::save(vector<string> &favGames, string &fileName) {
  ofstream file;
  file.open(fileName);
  for (int i = 0; i < favGames.size(); i++) {
    file << favGames[i] << endl;
  }
  file.close();
}
