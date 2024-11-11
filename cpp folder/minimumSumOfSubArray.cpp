// SUSAH
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> v, int i, int n)
{

    int m = INT_MAX, msf = 0;
    int p = v[i];
    for (int j = i; j < n; j++)
    {

        msf = min(msf + v[j], v[j]);
        if (msf < m)
            m = msf;
    }
    return m;
}
int main()
{
    int t;
    cout << "input T: ";
    cin >> t;
    while (t--)
    {
        int n;
        cout << "input n: ";
        cin >> n;
        vector<int> v;
        cout << "The [" << t << "]: ";
        for (int i = 0; i < n; i++)
        {
            int y;
            cin >> y;
            v.push_back(y);
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
            ans.push_back(fun(v, i, n));
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl
             << endl;
    }

    return 0;
}