#include "fileInteractions.h"

FileInteractions::FileInteractions() {}
// Loads the file into the vector
void FileInteractions::load(vector<string> &favGames, string fileName) {
  ifstream file;
  file.open(fileName);
  string game;
  while (getline(file, game)) {
    favGames.push_back(game);
  }
  file.close();
}

// Saves the vector to the file
void FileInteractions::save(vector<string> &favGames, string fileName) {
  ofstream file;
  file.open(fileName);
  for (int i = 0; i < favGames.size(); i++) {
    file << favGames[i] << endl;
  }
  file.close();
}

void FileInteractions::encriptedLoad(vector<string> &favGames, string fileName,
                                     const vector<int> &primes,
                                     const int &pass) {

  ifstream file;
  file.open(fileName);
  // Vector to store data from each line
  vector<vector<int>> data;
  // Read each line from the file
  string line;
  string value;

  while (getline(file, line)) {
    // Use a string stream to parse comma-separated values
    istringstream iss(line);
    vector<int> v1;
    // Read each value separated by commas
    while (getline(iss, value, ',')) {
      // Add the value to the vector
      v1.push_back(stoi(value));
    }
    data.push_back(v1);
  }
  // Close the file
  file.close();
  // Output the read data
  cout << "\nData read from the file:" << endl;
  for (int i = 0; i < data.size(); i++) {
    for (int j = 0; j < data[i].size(); j++) {
      cout << data[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  // decript the data and save to the vector
  cout << "Decripting the data..." << endl;
  string game = "";
  int gameCharInt = 0;
  int primeTotal = 0;
  for (int gameNum = 0; gameNum < data.size(); gameNum++) {
    for (int c = 0; c < data[gameNum].size(); c++) {
      primeTotal += primes[pass] * (c + 1);
      if (c < 1) {
        gameCharInt = ((data[gameNum][c] / primeTotal) / 1);
      } else {
        gameCharInt = ((data[gameNum][c] / primeTotal) / c);
      }
      char gameChar = gameCharInt;
      game += gameChar;
      gameCharInt = 0;
    }
    primeTotal = data.size() - data[gameNum].size() - gameNum;
    cout << game << endl;
    favGames.push_back(game);
    game = "";
  }
}

void FileInteractions::encriptedSave(vector<string> &favGames, string fileName,
                                     const vector<int> &primes,
                                     const int &pass) {
  ofstream file;
  file.open(fileName);
  string game = "";
  int gameCharInt = 0;
  int primeTotal = 0;
  for (int gameNum = 0; gameNum < favGames.size(); gameNum++) {
    for (int c = 0; c < favGames[gameNum].size(); c++) {
      primeTotal += primes[pass] * (c + 1);
      if (c < 1) {
        gameCharInt = (((int)favGames[gameNum][c] * primeTotal) * 1);
      } else {
        gameCharInt = (((int)favGames[gameNum][c] * primeTotal) * c);
      }

      game += to_string(gameCharInt);
      if (c < favGames[gameNum].size() - 1) {
        game.append(",");
      }
      gameCharInt = 0;
    }
    primeTotal = favGames.size() - favGames[gameNum].size() - gameNum;
    file << game << endl;
    cout << game << endl;
    game = "";
  }
  file.close();
}
