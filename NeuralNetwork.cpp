#include <vector>

class NeuralNetwork
{
public:
  // Constructor
  NeuralNetwork(const std::vector<int> &layerSizes);

  // Feedforward function
  std::vector<double> feedforward(const std::vector<double> &inputs);

private:
  std::vector<std::vector<Neuron>> layers;
};

NeuralNetwork::NeuralNetwork(const std::vector<int> &layerSizes)
{
  // Create the layers of the network
  for (size_t i = 0; i < layerSizes.size(); i++)
  {
    // Create a new layer
    std::vector<Neuron> layer;

    // Add the specified number of neurons to the layer
    for (int j = 0; j < layerSizes[i]; j++)
    {
      // Initialize the weights for the neuron
      std::vector<double> weights;
      // ...

      // Create the neuron and add it to the layer
      Neuron neuron(weights);
      layer.push_back(neuron);
    }

    // Add the layer to the network
    layers.push_back(layer);
  }
}

std::vector<double> NeuralNetwork::feedforward(const std::vector<double> &inputs)
{
  // Create a vector to hold the outputs from each layer
  std::vector<double> outputs;

  // Feed the inputs forward through the network
  for (size_t i = 0; i < layers.size(); i++)
  {
    // Get the current layer
    const std::vector<Neuron> &layer = layers[i];

    // Create a vector to hold the outputs from the current layer
    std::vector<double> layerOutputs;

    // Feed the inputs through the current layer
    for (size_t j = 0; j < layer.size(); j++)
    {
      // Get the current neuron
      const Neuron &neuron = layer[j];

      // Calculate the output of the neuron
      double output = neuron.activate(outputs);

      // Add the output to the vector of outputs for the layer
      layerOutputs.push_back(output);
    }

    // Add the outputs from the current layer to the overall outputs
    outputs.insert(outputs.end(), layerOutputs.begin(), layerOutputs.end());
  }

  return outputs;
}
