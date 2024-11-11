int n, k, i, j;
    cout << "N = ";
    cin >> n;
    cout << "K = ";
    cin >> k;

    int input[k];
    for (i = 0; i < k; i++)
    {
        cin >> input[i];
    }

    int a[n] = {0};
    i = 0;
    while (i < k)
    {
        j = 0;
        while (j < k)
        {
            if (j >= input[i] - 1)
            {
                a[j]++;
            }
            j++;
        }
        i++;
    }

    for (i = 0; i < n; i++)
        cout << a[i] << " ";