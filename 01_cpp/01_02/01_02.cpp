#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>

int main()
{
    std::ifstream file("input.txt");
    // std::ifstream file("test.txt");
    std::string line;

    int counter = 0;

    while (std::getline(file, line))
    {
        for (std::size_t i = 0; i < line.size(); ++i)
        {
            if (line[i] == '(')
            {
                counter++;
            }
            else if (line[i] == ')')
            {
                counter--;
                if (counter < 0)
                {
                    std::cout << "Position: " << i + 1 << std::endl;
                    break;
                }
            }
            else
            {
                std::runtime_error("Unexpected input char" + line[i]);
            }
        }
    }

    file.close();
    return 0;
}
