#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>

int main()
{
    std::ifstream file("input_extended.txt");
    // std::ifstream file("input.txt");
    // std::ifstream file("test.txt");
    std::string line;

    int counter = 0;

    while (std::getline(file, line))
    {
        for (char c : line)
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
    }

    std::cout << "Result: " << counter << std::endl;

    file.close();
    return 0;
}
