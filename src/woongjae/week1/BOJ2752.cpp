#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    int tmp;
    cin >> a >> b >> c;
    if (a > b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    if (b > c)
    {
        tmp = c;
        c = b;
        b = tmp;
    }
    if (a > b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    cout << a << " " << b << " " << c;
}