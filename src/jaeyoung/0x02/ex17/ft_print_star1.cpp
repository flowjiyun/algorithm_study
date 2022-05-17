#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i;
    int j;
    int n;

    i = 0;
    cin >> n;
    while (i < n)
    {
        j = 0;
        while (j <= i)
        {
            cout << '*';
            j++;
        }
        cout << '\n';
        i++;
    }
}