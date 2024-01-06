#include "./network.h"

void NeuralNetwork::randomize(float weightLimit, float biasLimit)
{
  for (int i = 0; i < columns.size; i++)
    columns[i].randomize(weightLimit, biasLimit);
}

Array<Array<float>> NeuralNetwork::activateFull(float *inputs)
{
  Array<Array<float>> output(columns.size);
  output[0] = columns[0].activate(inputs);
  for (int i = 1; i < columns.size; i++)
    output[i] = columns[i].activate(output[i - 1].data);
  return output;
}

Array<float> NeuralNetwork::activate(float *inputs)
{
  Array<Array<float>> output = activateFull(inputs);
  return output[output.size - 1];
}

// void NeuralNetwork::train(float **inputs, float **expectedOutputs, float learningRate, int batchSize)
void NeuralNetwork::train(Array<Array<float>> inputs, Array<Array<float>> expectedOutputs, float learningRate, int batchSize)
{
  for (int batch = 0; batch < batchSize; batch++)
    for (int x = 0; x < columns.size; x++)
      for (int y = 0; y < columns[x].neurons.size; y++)
      {
        Neuron *neuron = &columns[x].neurons[y];

        // Array<float *> outputs = activateFull(inputs[batch]);
        // Array<float *> outputs = activateFull(inputs[batch].data);
        // Array<float >> outputs = activateFull(inputs[batch].data);
        // Array<float> outputError = outputs[outputs.size];

        // for (int i = 0; i < outputs.size - 1; i++)
        // delete[] outputs[i];

        // for (int i = 0; i < outputError.size; i++)
        //   outputError[i] = outputs[outputs.size - 1][i] - expectedOutputs[batch][i];

        neuron->randomize(1.0, 1.0);
        // for (int i = 0; i < outputs.size - 1; i++)
        //   delete[] outputs[i];
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