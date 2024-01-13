#include "./network.h"

void NeuralNetwork::randomize(float weightLimit, float biasLimit)
{
  for (int i = 0; i < columns.size; i++)
    columns[i].randomize(weightLimit, biasLimit);
}

Array<Array<float>> NeuralNetwork::activateFull(float *inputs)
{
  Array<Array<float>> output(columns.size);
  output[0] = Array<float>(columns[0].activate(inputs), columns[0].neurons.size);
  for (int i = 1; i < columns.size; i++)
    output[i] = Array<float>(columns[i].activate(output[i - 1].data), columns[i].neurons.size);
  return output;
}

Array<float> NeuralNetwork::activate(float *inputs)
{
  Array<Array<float>> output = activateFull(inputs);
  return output[output.size - 1];
}

void NeuralNetwork::train(Array<Array<float>> inputs, Array<Array<float>> expectedOutputs, int epochs)
{
  float learningRate = 0.01f;
  for (int epoch = 0; epoch < epochs; epoch++)
  {
    for (int batch = 0; batch < inputs.size; batch++)
    {
      Array<Array<float>> outputs = activateFull(inputs[batch].data);
      outputs.insert(inputs[batch]);
      Array<Neuron> &column = columns[columns.size - 1].neurons;

      Array<float> delta_o = outputs[outputs.size - 1] - expectedOutputs[batch];
      delta_o *= -learningRate;

      Array<Array<float>> weights_diff(delta_o.size);

      for (int i = 0; i < delta_o.size; i++)
      {
        weights_diff[i] = Array<float>(outputs[outputs.size - 2].size);
        for (int j = 0; j < outputs[outputs.size - 2].size; j++)
          weights_diff[i][j] = delta_o[i] * outputs[outputs.size - 2][j];
      }

      Array<float> bias_diff = delta_o;
      for (int i = 0; i < weights_diff.size; i++)
      {
        columns[columns.size - 1].neurons[i].weights += weights_diff[i];
        columns[columns.size - 1].neurons[i].bias += bias_diff[i];
      }
    }
  }
}

NeuralNetwork::NeuralNetwork(Array<int> _columns)
{
  structure = _columns;
  columns = Array<NeuralColumn>(_columns.size - 1); // -1 for input layer

  if (columns.size == 0)
    throw std::runtime_error("Columns amount can't be 0");

  for (int i = 0; i < columns.size; i++)
    columns[i] = NeuralColumn(_columns[i], _columns[i + 1]);
}

NeuralNetwork::~NeuralNetwork() {}