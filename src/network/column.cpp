#include <iostream>
#include "./column.h"

void NeuralColumn::randomize(float weightLimit, float biasLimit)
{
  for (int i = 0; i < neurons.size; i++)
    neurons[i].randomize(weightLimit, biasLimit);
}

float *NeuralColumn::activate(float *inputs)
{
  float *sum = new float[neurons.size];
  for (int i = 0; i < neurons.size; i++)
    sum[i] = neurons[i].activate(inputs);

  return sum;
}

NeuralColumn::NeuralColumn() : neurons(0){};
NeuralColumn::NeuralColumn(int _inputsAmount, int _neuronsAmount)
    : neurons(_neuronsAmount)
{
  if (neurons.size == 0)
    throw std::runtime_error("Neurons amount can't be 0");

  for (int i = 0; i < neurons.size; i++)
    neurons[i] = Neuron(_inputsAmount);
}

NeuralColumn::~NeuralColumn(){};

// apply delta
void NeuralColumn::applyDelta(Array<float> delta, Array<float> outputs, float learningRate)
{
  Array<Array<float>> weights_diff(delta.size); // calculating weights difference
  for (int i = 0; i < delta.size; i++)
  {
    weights_diff[i] = Array<float>(outputs.size);
    for (int j = 0; j < outputs.size; j++)
      weights_diff[i][j] = delta[i] * -learningRate * outputs[j];
  }

  Array<float> bias_diff = delta * -learningRate; // calculating bias difference
  // implimenting weights and bias
  // columns[layer] = (Array<Array<float>>)columns[layer] + weights_diff;
  // columns[layer] = (Array<float>)columns[layer] + bias_diff;
  *this = (Array<Array<float>>)*this + weights_diff;
  *this = (Array<float>)*this + bias_diff;
  // Array<Array<float>> weights_diff(delta.size);

  // for (int i = 0; i < delta.size; i++)
  // {
  //   weights_diff[i] = Array<float>(outputs.size);
  //   for (int j = 0; j < outputs.size; j++)
  //     weights_diff[i][j] = delta[i] * outputs[j];
  // }

  // Array<float> bias_diff = delta;
  // for (int i = 0; i < weights_diff.size; i++)
  // {
  //   operator=(operator Array<float>() + bias_diff);
  //   operator=(operator Array<Array<float>>() + weights_diff);
  //   // columns[columns.size - 1].neurons[i].weights += weights_diff[i];
  //   // columns[columns.size - 1].neurons[i].bias += bias_diff[i];
  // }
}

// get biases and weights
NeuralColumn::operator Array<float>()
{
  Array<float> biases(neurons.size);
  for (int i = 0; i < biases.size; i++)
    biases[i] = neurons[i].bias;
  return biases;
};
NeuralColumn::operator Array<Array<float>>()
{
  Array<Array<float>> weights(neurons.size);
  for (int i = 0; i < weights.size; i++)
    weights[i] = neurons[i].weights;
  return weights;
};

// set biases and weights
void NeuralColumn::operator=(Array<float> biases)
{
  for (int i = 0; i < neurons.size; i++)
    neurons[i].bias = biases[i];
};
void NeuralColumn::operator=(Array<Array<float>> weights)
{
  for (int i = 0; i < neurons.size; i++)
    neurons[i].weights = weights[i];
};
