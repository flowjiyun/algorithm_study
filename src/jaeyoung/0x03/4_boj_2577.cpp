#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;
    int i;
    int sum;
    int num[9];
    int out[10];
    int size;

    sum = 1;
    i = 0;
    while (i < 10)
        out[i++] = 0;
    i = 0;
    while (i < 3)
    {
        cin >> a;
        sum *= a;
        i++;
    }
    size = 0;
    while (sum)
    {
        num[size] = sum % 10;
        sum = sum / 10;
        size++;
    }
    i = 0;
    while (i < size)
    {
      out[num[i]]++;
      i++;
    }
    i = 0;
    while (i < 10)
        cout << out[i++] << '\n';
}