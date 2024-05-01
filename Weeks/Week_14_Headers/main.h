#include "functions/robot.h"
#include "includes.h"

void printLoop(string phrase = "Gamers arise!!", int loopNum = 5) {
  for (int i = 0; i < loopNum; i++) {
    cout << phrase << endl;
  }
}
// Check to see if a string is a number
bool checkIfANumber(string input) {
  return all_of(input.begin(), input.end(), ::isdigit);
}