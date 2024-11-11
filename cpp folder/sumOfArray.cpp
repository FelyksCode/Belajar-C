#include <iostream>
using namespace std;

class hitung
{
public:
    int getSumArray(int n[], int size)
    {
        int result = 0;
        int i = 0;
        while (i < size)
        {
            result += n[i];
            i++;
        }

        return result;
    }
};

int main()
{
    hitung hitung;
    int arraySize;
    cout << "Array Size: ";
    cin >> arraySize;
    int n[arraySize];
    int i = 0;
    while (i < arraySize)
    {
        cout << "The " << i + 1 << " value: ";
        cin >> n[i];
        i++;
    }

    cout << hitung.getSumArray(n, arraySize);

    return 0;
}