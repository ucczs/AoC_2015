#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <array>

int main()
{
    std::ifstream file("input.txt");
    // std::ifstream file("test.txt");
    // std::ifstream file("test_2.txt");
    std::string line;

    std::getline(file, line);
    std::unordered_set<std::string> positions = {"0x0"};

    std::array<std::pair<int, int>, 2> pos;
    pos[0].first = 0;
    pos[0].second = 0;
    pos[1].first = 0;
    pos[1].second = 0;
    for (int i = 0; i < line.size(); ++i)
    {
        int guy = i % 2;
        switch (line[i])
        {
        case '^':
            pos[guy].second++;
            break;
        case 'v':
            pos[guy].second--;
            break;
        case '<':
            pos[guy].first++;
            break;
        case '>':
            pos[guy].first--;
            break;
        default:
            std::runtime_error("Wrong command detected!");
            break;
        }
        int x_pos = pos[guy].first;
        int y_pos = pos[guy].second;
        std::string pos = std::to_string(x_pos) + "x" + std::to_string(y_pos);
        positions.insert(pos);
    }
    int result = positions.size();

    std::cout << result << std::endl;

    file.close();
    return 0;
}
