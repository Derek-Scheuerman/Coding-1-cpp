// creating a perceptron
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Perceptron {
private:
  float learning_rate;
  float bias;
  vector<float> weights;

public:
  Perceptron(float learning_rate, float bias, vector<float> weights_) {
    this->learning_rate = learning_rate;
    this->bias = bias;
    for (int i = 0; i < weights_.size(); i++) {
      this->weights[i] = weights_[i];
    }
  }
  float get_learning_rate() { return this->learning_rate; }
  float get_bias() { return this->bias; }
  float get_weights(int index) { return this->weights[index]; }
  void set_learning_rate(float learning_rate) {
    this->learning_rate = learning_rate;
  }
  void set_bias(float bias) { this->bias = bias; }
  void set_weights(int index, float weight) { this->weights[index] = weight; }

  float predict(vector<float> inputs) {
    float sum = 0;
    for (int i = 0; i < inputs.size(); i++) {
      sum += inputs[i] * this->weights[i];
    }
    sum += this->bias;
    if (sum > 0) {
      return 1;
    } else {
      return 0;
    }
  }

  void train(vector<float> inputs, float target) {
    float prediction = this->predict(inputs);
    float error = target - prediction;
    for (int i = 0; i < inputs.size(); i++) {
      this->weights[i] += this->learning_rate * error * inputs[i];
    }
    this->bias += this->learning_rate * error;
  }
};