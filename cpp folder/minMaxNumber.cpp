#include <iostream>
using namespace std;

class calculator
{
public:
    int maxNumber(int numbers[], int size)
    {
        int max = numbers[0];
        int i = 0;
        while (i < size)
        {
            if (max < numbers[i])
                max = numbers[i];
            i++;
        }

        return max;
    }

    int minNumber(int numbers[], int size)
    {
        int min = numbers[0];
        int i = 0;
        while (i < size)
        {
            if (min > numbers[i])
                min = numbers[i];
            i++;
        }
        return min;
    }
};

int main()
{
    calculator c;
    int numbers[] = {1000, 11, 445, 1, 330, 3000};
    int arraySize = sizeof(numbers) / sizeof(numbers[0]);
    // int arraySize;
    // cout << "Array size: ";
    // cin >> arraySize;

    // int numbers[arraySize];
    // int i = 0;
    // while (i < arraySize)
    // {
    //     cout << "The " << i + 1 << " value: ";
    //     cin >> numbers[i];
    //     i++;
    // }

    cout << "Minimum element is: " << c.minNumber(numbers, arraySize) << endl;
    cout << "Maximum element is: " << c.maxNumber(numbers, arraySize) << endl;

    return 0;
}