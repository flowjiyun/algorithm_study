#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int i;
    int num[10] = {};
    int max;

    max = -1;
    cin >> n;
    i = 0;
    while(n)
    {
        num[n % 10]++;
        n = n / 10;
    }
    i = 0;
    while (i < 9)
    {
        if (num[i] > max && i !=6)
            max = num[i];
        i++;
    }
    if (max < num[6] || max < num[9])
    {
        if (num[6] == num[9])
            cout << num[6];
        if (num[6] != num[9])
        {
           num[9] += num[6];
           num[9] = (num[9] / 2) + (num[9] % 2);
           cout << num[9];
        }         
    }
    else
        cout << max;
}