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
    stack<pair<int, int>> s;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> m;

        while (!s.empty())
        {
            if (s.top().second > m)
            {
                cout << s.top().first << " ";
                break;
            }
            s.pop();
        }

        if (s.empty())
        {
            cout << "0 ";
        }

        s.push(make_pair(i + 1, m));
    }
    return 0;
}