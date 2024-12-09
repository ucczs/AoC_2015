#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <array>

bool contain_pair(const std::string &line, int limit = 3)
{
    std::regex regex("([a-z])([a-z]).*\\1\\2");
    return std::regex_search(line, regex);
}

bool double_letter(const std::string &line)
{
    std::regex regex("([a-z]).\\1");
    return std::regex_search(line, regex);
}

int main()
{

    std::ifstream file("input.txt");
    // std::ifstream file("test.txt");
    std::string line;

    int nice_count = 0;
    while (std::getline(file, line))
    {
        if (contain_pair(line) && double_letter(line))
        {
            nice_count++;
        }
    }

    std::cout << nice_count << std::endl;

    file.close();
    return 0;
}
