#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int i;
    int j;

    i = 0;
    cin >> n;
    while (i < n)
    {
        j = 0;
        while (j < n - i - 1)
        {
            cout << ' ';
            j++;
        }
        while (j < n)
        {
            cout << '*';
            j++;
        }
        cout << '\n';
        i++;
     }
}