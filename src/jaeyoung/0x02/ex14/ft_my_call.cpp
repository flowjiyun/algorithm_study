#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int arr[20];
    int i;
    int y;
    int m;

    i = 0;
    y = 0;
    m = 0;
    cin >> n;
    while (i < n)
        cin >> arr[i++];
    i = 0;
    while (i < n)
    {
        y += ((arr[i] / 30) + 1) * 10;
        i++;
    }
    i = 0;
    while (i < n)
    {
        m += ((arr[i] / 60) + 1) * 15;
        i++;
    }

    if (y == m)
        cout << "Y M " << y;
    if (y > m)
        cout << "M " << m;
    if (y < m)
        cout << "Y " << y;
}
