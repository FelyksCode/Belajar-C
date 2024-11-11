#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class calc
{
public:
    void reduceForm(int arr[], int n)
    {
        map<int, int> m;

        int ans[n];
        cout << "ans: ";
        for (int i = 0; i < n; i++)
        {
            ans[i] = arr[i];
            cout << ans[i] << " ";
        }
        cout << endl;
        sort(ans, ans + n);
        cout << "m[ans[i]]: ";
        for (int i = 0; i < n; i++)
        {
            m[ans[i]] = i;
            cout << m[ans[i]] << " ";
        }
        cout << endl;
        cout << "arr: ";
        for (int i = 0; i < n; i++)
        {
            arr[i] = m[arr[i]];
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int arr[] = {5, 10, 40, 30, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    calc c;
    c.reduceForm(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}