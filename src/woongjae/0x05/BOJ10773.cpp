#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    int n;
    int sum;
    stack<int> S;

    sum = 0;
    cin >> k;
    while (k--)
    {
        cin >> n;
        if (n == 0)
        {
            sum -= S.top();
            S.pop();
        }
        else
        {
            S.push(n);
            sum += S.top();
        }
    }
    cout << sum;
}