#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int x;
    string s;
    
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (s == "push")
        {
            cin >> x;
            q.push(x);
        }
        else if (s == "pop")
        {
            if (!q.empty())
            {
                cout << q.front() << '\n';
                q.pop();
            }
            else
                cout << "-1" << '\n';
        }
        else if (s == "size")
            cout << q.size() << '\n';
        else if (s == "empty")
        {       
           cout << q.empty() << '\n';
        }
        else if (s == "front")
        {
            if (!q.empty())
                cout << q.front() << '\n';
            else
                cout << "-1" << '\n';
        }
        else
        {
            if (!q.empty())
                cout << q.back() << '\n';
            else
                cout << "-1" << '\n';
        }
    }
}