#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int i;

    cin >> i;
    if (i >= 90)
        cout << "A";
    else if (i >= 80)
        cout << "B";
    else if (i >= 70)
        cout << "C";
    else if (i >= 60)
        cout << "D";
    else 
        cout << "F";
    
}