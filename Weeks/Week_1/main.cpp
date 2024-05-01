#include <cstdlib> // fpr generating random numbers
#include <ctime>   // for seeding the random number generator
#include <iostream>
#include <string>
using namespace std;

void numrun() {
  int num1;
  int num2;
  cout << "\nPlease Enter a number: ";
  cin >> num1;
  cout << "Please Enter a second number: ";
  cin >> num2;
  if (num1 + num2 >= 18) {
    cout << "num1 * num2 = " << num1 * num2 << "\n";
  } else {
    cout << "num1 + num2 = " << num1 + num2 << "\n";
  }
}

int main() {
  srand(time(0));
  // Hello world
  bool looper = true;
  int kinky = 0;
  string kink = "";
  string player_color = "";
  string playerName = "";
  bool player_aged = true;
  int player_age = 0;
  int player_age_days = 0;
  int tf = 0;
  string computerpromt = "My favorite is black.\nWhat's your favorite color? :";
  cout << "\nWhat is your name?: ";
  cin >> playerName;
  cout << "\n";
  cout << computerpromt;
  cin >> player_color;
  cout << "\n";
  cout << "Hello " << playerName << "\nWhat is your age?: ";
  cin >> player_age;
  player_age_days = player_age * 365.25;
  cout << "\n\n"; // need space!!
  cout << "Your name is " << playerName << "\nYour age is " << player_age
       << "\nYour favorite color is " << player_color;

  if (player_age < 30) {
    player_aged = false;
  }
  if (player_aged == true) {
    cout
        << "\nYou are to old enough to play this game.\nGet a life.\nYou are a "
        << player_color << " person.\n"
        << "You are " << player_age_days << " days old.\n"
        << "You are " << player_age << " years old.\n";
  } else {
    cout << "\nYou are to young to play this game. \nYou are a " << player_color
         << "person.\nYou are " << player_age_days << " days old.\n"
         << "You are " << player_age << " years old.\n";
  }

  cout << "\n\n";
  cout << "Hello " << playerName << "!\n";
  cout << "Are you ready to start programming?\n";
  cout << "Experiment time";
  cout << "Here is a random number: " << rand() << "\n";
  cout << "Here is a constrained random number 1-20: " << (rand() % 20 + 1)
       << "\n";
  cout << "Here is a random number: " << rand() << "\n";
  cout << "Here is a constrained random number 1-20: " << (rand() % 20 + 1)
       << "\n";
  cout << "Here is a  random Year 1970-2019: " << (rand() % 50 + 1970) << "\n";
  cout << "Here is a  random Year 1970-2019: " << (rand() % 50 + 1970) << "\n";
  numrun();

  while (looper) {
    cout << "Try again?(YES = 1 / NO = 0)\n";
    cin >> tf;

    if (tf == 1) {
      numrun();
    } else {
      cout << "\nGoodbye";
      looper = false;
    }
    cout << "Are you kinky?(YES = 1 / NO = 0)\n\n";
    cin >> kinky;
    if (kinky == 1) {
      cout << "What's your kink:";
      cin >> kink;
      cout << "\nYou are a failer of a human being if you have a kink of ("
           << kink << ").\n";
    }
  }
}