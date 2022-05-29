#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> Q;
    int nb;
    cin >> nb;
    for (int i = 1; i <= nb; i++)
        Q.push(i);
    while (Q.size() != 1)
    {
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }
    cout << Q.front();
    return (0);
}