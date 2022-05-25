#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, cnt;
    stack<int> s;

    cin >> n;

    while (n--)
    {
        cin >> m;

        if (m)
            s.push(m);
        else
            s.pop();
    }

    cnt = 0;
    while (!s.empty())
    {
        cnt += s.top();
        s.pop();
    }

    cout << cnt;
    return 0;
}