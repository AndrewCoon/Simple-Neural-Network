#include <vector>

class Neuron
{
public:
  // Constructor
  Neuron(const std::vector<double> &weights);

  // Activation function
  double activate(const std::vector<double> &inputs);

private:
  std::vector<double> weights;
};

Neuron::Neuron(const std::vector<double> &weights)
  : weights(weights)
{
  // Initialize the weights for the neuron
  // ...
}

double Neuron::activate(const std::vector<double> &inputs)
{
  // Calculate the dot product of the input values and weights
  double sum = 0.0;
  for (size_t i = 0; i < weights.size(); i++)
  {
    sum += weights[i] * inputs[i];
  }

  // Apply the activation function to the sum
  double output = 1.0 / (1.0 + exp(-sum));

  return output;
}
