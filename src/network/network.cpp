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
  for (int epoch = 0; epoch < epochs; epoch++)
    for (int batch = 0; batch < inputs.size; batch++)
    {
      // if (rand() % 10 == 0) // randomly skip a batch
      //   continue;

      // learning
      // changes over epochs
      float learningRate = 1.0 / (1.0 + epoch);
      // float learningRate = 0.1;
      Array<Array<float>> outputs = activateFull(inputs[batch].data);
      outputs.insert(inputs[batch]);

      Array<float> delta = outputs[outputs.size - 1] - expectedOutputs[batch];
      for (int layer = columns.size - 1; layer >= 0; layer--)
      {
        columns[layer].applyDelta(delta, outputs[layer], learningRate);
        if (layer == 0)
          continue;

        Array<Array<float>> weights_transposed = transpose((Array<Array<float>>)columns[layer]);
        Array<Array<float>> l_delta = matrixMultiplication(weights_transposed, transpose(Array<Array<float>>({delta})));
        l_delta *= (outputs[layer] * (Array<float>(1, outputs[layer].size) - outputs[layer]));
        delta = transpose(l_delta)[0];
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
