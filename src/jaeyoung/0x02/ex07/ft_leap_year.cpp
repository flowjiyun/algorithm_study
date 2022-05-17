#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i;

    cin >> i;
    if (i % 4 == 0)
    {
        if (i % 400 == 0)
            cout << "1";
        else if (i % 100 == 0)
            cout << "0";
        else 
            cout << "1";
    }
    else
        cout << "0";    
}