#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cout << "N = ";
    cin >> n;
    cout << "K = ";
    cin >> k;

    int input[k];
    for (int i = 0; i < k; i++)
    {
        cin >> input[i];
    }

    int a[n] = {0};
    for (int i = 0; i < k; i++)
    {
        a[input[i] - 1]++;
    }

    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}