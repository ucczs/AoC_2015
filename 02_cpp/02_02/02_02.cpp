#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>

auto split_string(std::string full_string, char seperator) -> std::vector<std::string>
{
    std::stringstream full_string_ss(full_string);
    std::vector<std::string> splitted_string;
    std::string split;

    while (std::getline(full_string_ss, split, seperator))
    {
        if (split[0] == ' ')
        {
            split = split.substr(1, split.length() - 1);
        }
        splitted_string.push_back(split);
    }

    return splitted_string;
}

auto stringVec2intVec(std::vector<std::string> *vec_str) -> std::vector<int>
{
    std::vector<int> vec_int;
    std::transform(vec_str->begin(), vec_str->end(), std::back_inserter(vec_int), [](const std::string &str)
                   { return std::stoi(str); });
    return vec_int;
}

int main()
{
    std::ifstream file("input.txt");
    // std::ifstream file("test.txt");
    // std::ifstream file("test_2.txt");
    std::string line;

    int count = 0;

    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
        auto values_str = split_string(line, 'x');
        auto values = stringVec2intVec(&values_str);
        std::sort(values.begin(), values.end(), [](const int &a, const int &b)
                  { return a < b; });
        int perimeter = (values[0] + values[1]) * 2;
        int bow = std::accumulate(values.begin(), values.end(), 1, std::multiplies<int>());
        count += perimeter + bow;
    }
    std::cout << count << std::endl;

    file.close();
    return 0;
}
