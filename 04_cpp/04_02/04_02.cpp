#include <iostream>
#include <openssl/md5.h>
#include <string>
#include <iomanip>
#include <sstream>

std::string calculateMD5(const std::string &input)
{
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5(reinterpret_cast<const unsigned char *>(input.c_str()), input.size(), digest);

    std::ostringstream ss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
    }
    return ss.str();
}

int main()
{
    std::string input = "bgvyzdsv";
    std::string hash = "xxxxxxxxx";

    int i = 0;
    while (hash.substr(0, 6) != "000000")
    {
        i++;
        hash = calculateMD5(input + std::to_string(i));
    }

    std::cout << i << std::endl;
    return 0;
}
