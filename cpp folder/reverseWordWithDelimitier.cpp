#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
using std::string;

int main()
{
    // string inputString = "section1.section2.section3";

    string inputString;
    std::cout << "Input String: ";
    std::getline(std::cin, inputString);

    // Create a stringstream from the input string
    std::stringstream ss(inputString);

    // Vector to store sections
    std::vector<string> sections;

    // Tokenize the string using '.' as a delimiter
    string section;
    while (std::getline(ss, section, '.'))
    {
        sections.push_back(section);
    }

    string reversedString;
    for (const auto &str : sections)
    {
        string reversedSection = str;
        std::reverse(reversedSection.begin(), reversedSection.end());
        reversedString += reversedSection + ".";
    }

    if (!reversedString.empty())
    {
        reversedString.pop_back();
    }

    std::cout << "Word    : " << inputString << std::endl;
    std::cout << "Reversed: " << reversedString;

    return 0;
}
