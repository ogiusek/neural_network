#include <iostream>
#include <fstream>

// Function to read binary file and convert data to the desired type
template <typename T>
std::pair<size_t, T *> readBinaryFile(const std::string &filePath, size_t bytesToIgnore = 0)
{
  std::ifstream file(filePath, std::ios::binary);
  if (!file)
    throw std::runtime_error("Failed to open file: " + filePath);

  // Ignore the specified number of bytes at the beginning of the file
  file.seekg(bytesToIgnore, std::ios::beg);

  // Get the size of the file
  file.seekg(0, std::ios::end);
  size_t fileSize = file.tellg();
  file.seekg(bytesToIgnore, std::ios::beg);

  // Create a buffer of the exact size of the file
  char *buffer = new char[fileSize - bytesToIgnore];

  // Read the binary data into the buffer
  file.read(buffer, fileSize - bytesToIgnore);

  // Close the file
  file.close();

  // Convert the data to the desired type
  T *data = reinterpret_cast<T *>(buffer);

  // Return a pair containing the size of the array and the pointer to the array
  return {(fileSize - bytesToIgnore) / sizeof(T), data};
}