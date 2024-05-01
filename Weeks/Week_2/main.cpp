#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

void num20Rand() {
    int counter = 0;
    int numHigh = 0;
    int numLow = 100;
    int sum = 0;
    int avg =0;
    int numRand = 0;
    int evenCount =0;
    while (counter < 20){
        numRand = (rand() % 50 + 50);
        cout << numRand << endl;
        if (numRand > numHigh){
            numHigh = numRand;}
        if (numRand < numLow){
            numLow = numRand;}
        if (numRand % 2 == 0){
            evenCount++;}
        sum += numRand;
        counter++;
    } // end of while loop
    avg = sum / 20;
    cout << "The highest number is: " << numHigh << endl;
    cout << "The Lowest number is: " << numLow << endl;
    cout << "The sum of the numbers is: " << sum << endl;
    cout << "The average of the numbers is: " << avg << endl;
    cout << "The number of even numbers is: " << evenCount << endl;
    cout << "End of test\n\n\n";
}

void numRandTillOdd() {
    while(true){
        int randomNumber = rand() % 50 + 50;
        cout << randomNumber << endl;
        if(randomNumber %2){
            cout << "Found a random number that is odd. Stopping now\n";
            break;
        }// end of if statement
    }// end of while loop
    cout << "End of test\n\n\n";
}

void GuessRand(){
    int randomNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    bool correctGuess = false;
    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I'm thinking of a number between 1 and 100.\n";
    while (!correctGuess){
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;
        if (guess < randomNumber){
            std::cout << "Too low! Try again.\n";
        }
        if (guess > randomNumber){
            std::cout << "Too high! Try again.\n";
        }
        if (guess == randomNumber){
            std::cout << "You guessed it!\nTry again?";
            correctGuess = true;

        }

    }
}

int main() { 
    // high score finder, isEven, random numbers, switches, enums
    // random number between 50-100
    srand(time(0));
    num20Rand();
    numRandTillOdd();
    GuessRand();

} // end of int main