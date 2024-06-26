#include "Includes.h"
#include "fileInteractions.h"

vector<string> favGames;
const vector<int> primes = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,
                            31,  37,  41,  43,  47,  53,  59,  61,  67,  71,
                            73,  79,  83,  89,  97,  101, 103, 107, 109, 113,
                            127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
                            179, 181, 191, 193, 197, 199, 211, 223, 227};
const int key = 3; // must be less than the max index of primes
string fileName = "favGames.txt";
string encriptedFileName = "favGamesEncripted.txt";

bool optionMenu();
void addGame();
void editGame();
void showGames();
void removeGame();
void clearGames();