#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <array>

bool enough_vowels(const std::string &line, int limit = 3)
{
    const std::string vowels = "aeiou";

    int vowel_count = 0;
    for (const char &c : line)
    {
        if (vowels.find(c) != std::string::npos)
        {
            vowel_count++;
        }
    }

    return vowel_count >= limit;
}

bool double_letter(const std::string &line)
{
    std::regex regex("([a-zA-Z])\\1");
    return std::regex_search(line, regex);
}

bool no_forbidden_strings(const std::string &line)
{
    const std::array<std::string, 4> forbiddens = {"ab", "cd", "pq", "xy"};
    for (const std::string &forbidden : forbiddens)
    {
        if (line.find(forbidden) != std::string::npos)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    std::ifstream file("input.txt");
    // std::ifstream file("test.txt");
    std::string line;

    int nice_count = 0;
    while (std::getline(file, line))
    {
        if (enough_vowels(line) && double_letter(line) && no_forbidden_strings(line))
        {
            nice_count++;
        }
    }

    std::cout << nice_count << std::endl;

    file.close();
    return 0;
}
