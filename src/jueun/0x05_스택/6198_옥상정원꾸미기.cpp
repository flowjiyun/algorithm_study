#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    long long cnt;
    stack<int> s;

    cin >> n;

    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> m;

        while (!s.empty())
        {
            if (s.top() > m)
                break;
            s.pop();
        }

        cnt += (long long)s.size();
        s.push(m);
    }

    cout << cnt;
    return 0;
}