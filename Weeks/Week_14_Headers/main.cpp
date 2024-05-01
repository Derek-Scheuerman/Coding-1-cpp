#include "main.h"

int main() {
  srand(time(0));
  vector<string> names;
  ofstream myfile;
  myfile.open("example.txt", ios::app);
  myfile << "Writing this to a file.\n";
  myfile.close();

  ifstream nameFile("Names.txt");
  string line;
  if (nameFile.is_open()) {
    while (getline(nameFile, line)) {
      names.push_back(line);
    }
  } else {
    cout << "Unable to open file (Names.txt)";
  }
  nameFile.close();

  cout << "\n\nNames: " << endl;
  for (int i = 0; i < names.size(); i++) {
    cout << "Name ID: " << i << " Name: " << names[i] << endl;
  }
  cout << "Random name: " << names[rand() % names.size()] << endl;
  int randNum = rand() % names.size();
  string name = ("Name ID: " + to_string(randNum) + " Name: " + names[randNum]);
  printLoop(name);

  return 0;

  string inputText = "";
  int inputNumber = 0;
  cout << "Hello World!\n";
  printLoop();
  printLoop("Hello gamer!", 5);

  cout << "Enter a phrase to repeat: \n";
  getline(cin, inputText);
  string input;

  while (inputText != "quit") {
    cout << "Enter a number: \n";

    getline(cin, input);
    if (checkIfANumber(input)) {
      inputNumber = stoi(input);
      break;
    } else {
      cout << "Invalid input. Please enter a number.\n";
    }
  }
  printLoop(inputText, inputNumber);
  Robot bob = Robot("Bob", 50);
  bob.Status();
}