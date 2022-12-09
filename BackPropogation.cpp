#include <vector>

void NeuralNetwork::train(const std::vector<double> &inputs, const std::vector<double> &targets, double learningRate)
{
  // Feed the inputs forward through the network
  std::vector<double> outputs = feedforward(inputs);

  // Calculate the errors for each output neuron
  std::vector<double> outputErrors;
  for (size_t i = 0; i < outputs.size(); i++)
  {
    double error = targets[i] - outputs[i];
    outputErrors.push_back(error);
  }

  // Propagate the errors backwards through the network
  for (int i = layers.size() - 1; i >= 0; i--)
  {
    // Get the current layer
    std::vector<Neuron> &layer = layers[i];

    // Create a vector to hold the errors for the current layer
    std::vector<double> layerErrors;

    // Propagate the errors backwards through the current layer
    for (size_t j = 0; j < layer.size(); j++)
    {
      // Get the current neuron
      Neuron &neuron = layer[j];

      // Calculate the error for the neuron
      double error = 0.0;
      for (size_t k = 0; k < outputErrors.size(); k++)
      {
        error += outputErrors[k] * neuron.weights[k];
      }
      layerErrors.push_back(error);

      // Update the weights and biases of the neuron
      for (size_t k = 0; k < neuron.weights.size(); k++)
      {
        neuron.weights[k] += learningRate * outputErrors[k] * neuron.outputs[k];
        neuron.bias += learningRate * outputErrors[k];
      }
    }

    // Set the errors for the next layer to the errors for the current layer
    outputErrors = layerErrors;
  }
}
