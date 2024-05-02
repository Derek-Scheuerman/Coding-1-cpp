#include "Perceptron.cpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> board;

void setup() {
  // create base board
  for (int i = 0; i < 16; i++) {
    vector<int> row;
    for (int j = 0; j < 16; j++) {
      row.push_back(0);
    }
    board.push_back(row);
  }
}

void draw() {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
}

// Learning about neural networks
int main() {
  float LO = -1.0;
  float HI = 1.0;
  float target = 1.0;
  srand(time(0));
  cout << "Hello World!\n";
  cout << "In this program, we are going to create a perceptron and train it.\n "
      << endl;
  setup();
  cout << "Base board created: \n";
  draw();    

  cout << "Pleas enter the number of inputs: ";
  int num_inputs;
  cin >> num_inputs;
  cout << "Pleas enter the number of outputs: ";
  int num_outputs;
  cin >> num_outputs;
  cout << "Pleas enter the number of hidden layers: ";
  int num_hidden_layers;
  cin >> num_hidden_layers;
  cout << "Pleas enter the number of neurons in each hidden layer: ";
  int num_neurons_per_hidden_layer;
  cin >> num_neurons_per_hidden_layer;
  cout << "Pleas enter the number of training runs: ";
  int num_trainings;
  cin >> num_trainings;
  cout << "Pleas enter the learning rate: ";
  float learning_rate;
  cin >> learning_rate;
  cout << "Pleas enter the bias: ";
  float bias;
  cin >> bias;

  cout << "\n\nWeights: \n";
  vector<float> weights;
  for (int i = 0; i < ((num_inputs * num_neurons_per_hidden_layer) +
                       (num_hidden_layers * num_neurons_per_hidden_layer *
                        num_neurons_per_hidden_layer) +
                       num_neurons_per_hidden_layer * num_outputs);
       i++) {
    float weight = LO + static_cast<float>(rand()) /
                            (static_cast<float>(RAND_MAX) / (HI - LO));
    weights.push_back(weight);
    cout << "weight " << i << ": " << weight << endl;
  }

  cout << "\n\nInputs: \n";
  vector<float> inputs;
  for (int i = 0; i < num_inputs; i++) {
    float input = -10.0 + static_cast<float>(rand()) /
                              (static_cast<float>(RAND_MAX) / (100 + 10));
    inputs.push_back(input);
    cout << "input " << i << ": " << input << endl;
  }

  Perceptron perc = Perceptron(learning_rate, bias, weights);
  cout << "\n\nhere \n";
  for (int i = 0; i < num_trainings; i++) {
    for (int j = 0; j < inputs.size(); j++) {
      perc.train(inputs, target);
    }
  }

  for (int j = 0; j < board.size(); j++) {
    for (int k = 0; k < board[j].size(); k++) {
      board[j][k] = perc.predict(inputs);
    }
  }

  cout << "\n\nBoard after training: \n";
  draw();
}