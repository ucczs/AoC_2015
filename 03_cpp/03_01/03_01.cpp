#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>

int main()
{
    std::ifstream file("input.txt");
    // std::ifstream file("test.txt");
    // std::ifstream file("test_2.txt");
    std::string line;

    std::getline(file, line);
    std::unordered_set<std::string> pos_set = {"0x0"};

    int x_pos = 0;
    int y_pos = 0;
    for (char c : line)
    {
        switch (c)
        {
        case '^':
            y_pos++;
            break;
        case 'v':
            y_pos--;
            break;
        case '<':
            x_pos--;
            break;
        case '>':
            x_pos++;
            break;
        default:
            std::runtime_error("Wrong command detected!");
            break;
        }
        std::string pos = std::to_string(x_pos) + "x" + std::to_string(y_pos);
        pos_set.insert(pos);
    }
    int result = pos_set.size();

    std::cout << result << std::endl;

    file.close();
    return 0;
}
