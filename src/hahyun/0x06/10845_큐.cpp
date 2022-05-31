#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    queue<int> q;

    while (N--)
    {
        string com;
        cin >> com;
        if (com == "push")
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (com == "pop")
        {
            if (!q.empty())
            {
                cout << q.front() << '\n';
                q.pop();
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (com == "size")
        {
            cout << q.size() << '\n';
        }
        else if (com == "empty")
        {
            if (q.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (com == "front")
        {
            if (!q.empty())
                cout << q.front() << '\n';
            else
                cout << "-1\n";
        }
        else
        {
            if (!q.empty())
                cout << q.back() << '\n';
            else
                cout << "-1\n";
        }
    }
}