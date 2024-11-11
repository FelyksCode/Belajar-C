#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class calculator
{
public:
    void modus(int n[], int size)
    {
        vector<bool> visited(size, false);

        for (int i = 0; i < size; i++)
        {
            if (visited[i] == true)
                continue;

            int count = 1;
            for (int j = i + 1; j < size; j++)
            {
                if (n[i] == n[j])
                {
                    visited[j] = true;
                    count++;
                }
            }
            cout << n[i] << " " << count << endl;
        }
    }
};

int main()
{
    calculator c;
    int n[] = {10, 20, 20, 10, 10, 20, 5, 20};
    int arraySize = sizeof(n) / sizeof(n[0]);
    c.modus(n, arraySize);
    return 0;
}