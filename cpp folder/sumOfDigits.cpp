#include <iostream>
using namespace std;

class hitung
{
public:
    int getSum(int n)
    {
        int x, sum = 0;
        while (n != 0)
        {
            x = n % 10;
            sum += x;
            n = n / 10;
        }
        return sum;
    }
};

int main()
{
    int n;
    // n = 678;
    hitung result;
    cout << "n = ";
    cin >> n;

    cout << result.getSum(n);

    return 0;
}