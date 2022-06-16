#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;
    int n;
    string str;

    cin >> n;

    while (n--)
    {
        cin >> str;

        if (str == "push")
        {
            int m;
            cin >> m;
            q.push(m);
        }

        else if (str == "pop")
        {
            if (q.empty())
                cout << "-1\n";
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }

        else if (str == "size")
            cout << q.size() << "\n";

        else if (str == "empty")
            cout << q.empty() << "\n";

        else if (str == "front")
        {
            if (q.empty())
                cout << "-1\n";
            else
                cout << q.front() << "\n";
        }

        else
        {
            if (q.empty())
                cout << "-1\n";
            else
                cout << q.back() << "\n";
        }
    }
    return 0;
}