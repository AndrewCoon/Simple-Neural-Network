public class Neuron {
  // The weights of the connections to this neuron
  private double[] weights;

  // The input values for this neuron
  private double[] inputs;

  // The bias value for this neuron
  private double bias;

  // The activation function for this neuron
  private ActivationFunction activationFunction;

  // Constructor for creating a neuron with the given number of inputs
  public Neuron(int numInputs, ActivationFunction activationFunction) {
    this.weights = new double[numInputs];
    this.inputs = new double[numInputs];
    this.bias = Math.random();
    this.activationFunction = activationFunction;
  }

  // Set the input values for this neuron
  public void setInputs(double[] inputs) {
    this.inputs = inputs;
  }

  // Calculate the output value of this neuron
  public double getOutput() {
    double weightedSum = 0.0;

    // Calculate the weighted sum of the inputs
    for (int i = 0; i < weights.length; i++) {
      weightedSum += inputs[i] * weights[i];
    }

    // Add the bias value
    weightedSum += bias;

    // Apply the activation function to the weighted sum
    return activationFunction.apply(weightedSum);
  }
}
