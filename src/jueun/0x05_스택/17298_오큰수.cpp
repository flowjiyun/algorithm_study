#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    vector<int> v;
    stack<int> res;
    stack<int> s;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> m;
        v.push_back(m);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= v[i])
        {
            s.pop();
        }

        if (s.empty())
            res.push(-1);
        else
            res.push(s.top());

        s.push(v[i]);
    }

    while (!res.empty())
    {
        cout << res.top() << " ";
        res.pop();
    }
    return 0;
}