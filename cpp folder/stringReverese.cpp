#include <iostream>
#include <algorithm>
#include <string>
using std::string;

class Solution
{
public:
    string revStr(string S)
    {
        std::reverse(S.begin(), S.end());

        std::cout << "Reversed: " << S << std::endl;
        return S;
    }
};

int main()
{
    string word;
    std::cout << "Input the word that want to reverse: ";
    std::getline(std::cin, word);

    Solution solution;
    string reversedString = solution.revStr(word);

    return 0;
}
