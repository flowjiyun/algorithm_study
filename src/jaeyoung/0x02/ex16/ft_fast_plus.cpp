#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;
    int b;
    int n;
    int i;

    i = 0;
    cin >> n;
    while (i < n)
    {
        cin >> a >> b;
        cout << a + b << '\n';
        i++;
    }
}