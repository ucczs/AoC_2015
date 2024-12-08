#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>
#include <future>
#include <vector>

const auto processor_count = std::thread::hardware_concurrency();

uint32_t getSum(std::string chars)
{
    uint32_t counter = 0;
    for (char c : chars)
    {
        if (c == '(')
        {
            counter++;
        }
        else if (c == ')')
        {
            counter--;
        }
        else
        {
            std::runtime_error("Unexpected input char" + c);
        }
    }
    return counter;
}

std::vector<std::string> splitIntoEvenParts(const std::string &input, uint8_t part_count)
{
    const size_t totalLength = input.length();
    const size_t partLength = totalLength / part_count; // Base length of each part
    const size_t remainder = totalLength % part_count;  // Extra characters to distribute

    std::vector<std::string> parts;
    size_t start = 0;

    for (size_t i = 0; i < part_count; ++i)
    {
        size_t currentPartLength = partLength + (i < remainder ? 1 : 0); // Distribute remainder
        parts.push_back(input.substr(start, currentPartLength));
        start += currentPartLength;
    }

    return parts;
}

int main()
{
    std::ifstream file("input_extended.txt");
    // std::ifstream file("input.txt");
    // std::ifstream file("test.txt");
    std::string line;

    int counter = 0;

    std::getline(file, line);
    std::vector<std::string> line_vec = splitIntoEvenParts(line, processor_count);

    std::vector<std::future<uint32_t>> futures;

    // Launch threads
    for (int i = 0; i < processor_count; ++i)
    {
        futures.push_back(std::async(std::launch::async, getSum, line_vec[i]));
    }

    // Retrieve results
    for (int i = 0; i < processor_count; ++i)
    {
        uint32_t result = futures[i].get();
        counter += result;
    }

    std::cout << "Result: " << counter << std::endl;

    file.close();
    return 0;
}
