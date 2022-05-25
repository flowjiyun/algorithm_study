#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, idx;
    vector<int> v;
    vector<char> c;
    stack<int> s;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> m;
        v.push_back(m);
    }

    i = 1;
    idx = 0;
    s.push(0);

    while (idx < n)
    {
        if (i > n + 1)
        {
            cout << "NO";
            return 0;
        }

        if (s.top() < v[idx])
        {
            s.push(i);
            c.push_back('+');
            i++;
        }
        else if (s.top() > v[idx])
        {
            if (s.top() == 0 || s.empty())
            {
                cout << "NO";
                return 0;
            }
            else
            {
                s.pop();
                c.push_back('-');
            }
        }
        else
        {
            s.pop();
            c.push_back('-');
            idx++;
        }
    }

    for (auto ans : c)
        cout << ans << "\n";
    return 0;
}