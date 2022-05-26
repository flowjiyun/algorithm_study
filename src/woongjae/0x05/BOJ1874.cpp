#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int x;
    int i;
    stack<int> S;
    string ans;

    i = 1;
    cin >> n;

    while (n--)
    {
        cin >> x;
        while (S.empty() || S.top() < x)
        {
            S.push(i);
            i++;
            ans += "+\n";
        }
        if (S.top() != x)
        {
            cout << "NO";
            return (0);
        }
        S.pop();
        ans += "-\n";
    }
    cout << ans;
    return (0);
}