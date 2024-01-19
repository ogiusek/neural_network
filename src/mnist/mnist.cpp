#include "../main.h"

namespace Mnist
{
  Array<Array<float>> getImages(bool test = false)
  {
    auto [trainImgSize, trainImgData] = readBinaryFile<char>(test ? "./mnist/test-images" : "./mnist/train-images", 16);
    Array<Array<float>> processedInputs(trainImgSize / 784);
    for (int i = 0; i < trainImgSize / 784; i++)
    {
      processedInputs[i] = Array<float>(784);
      for (int j = 0; j < 784; j++)
        processedInputs[i][j] = trainImgData[i * 784 + j] / 255.0;
    }
    return processedInputs;
  }
  Array<Array<float>> getLabels(bool test = false)
  {
    auto [trainLabelSize, trainLabelData] = readBinaryFile<char>(test ? "./mnist/test-labels" : "./mnist/train-labels", 8);
    Array<Array<float>> processedLabels(trainLabelSize);
    for (int i = 0; i < processedLabels.size; i++)
    {
      processedLabels[i] = Array<float>(10);
      for (int j = 0; j < 10; j++)
        processedLabels[i][j] = trainLabelData[i] == j ? 1.0 : 0.0;
    }
    return processedLabels;
  }

  std::pair<Array<Array<float>>, Array<Array<float>>> getProcessedData(bool test = false) { return {getImages(test), getLabels(test)}; }
}