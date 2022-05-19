#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[9];
    int i;
    int sum;
    int j;
    int k;

    sum = 0;
    i = 0;
    while (i < 9)
    {
        cin >> a[i];
        sum += a[i];
        i++;
    }
    sort(a, a + 9);
    i = 0;
    while (i < 9)
    {
        j = 1;
        while (j < 9)
        {
            if (sum - (a[i] + a[j]) == 100)
            {
                k = 0;
                while (k < 9)
                {
                    if (k != i && k != j)
                        cout << a[k] << '\n';
                    k++;
                }
                return (0);
            }
            j++;
        }
        i++;
    }
    return (0);
}