#include <iostream>
#include <string>
using namespace std;

class check
{
public:
    bool palindrom(string word)
    {
        int l, h;
        l = 0;
        h = word.length() - 1;

        while (h > l)
        {
            if (word[l++] != word[h--])
            {
                cout << word << " is not palindrom";
                return 0;
            }
        }
        cout << word << " is palindrom";
        return 1;
    }
};

int main()
{
    string word;
    check check;

    cout << "input word: ";
    getline(cin, word);

    check.palindrom(word);

    return 0;
}
