#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    deque<int> dq;

    cin >> n;
    while (n--)
    {
        cin >> s;
        if (s == "push_front")
        {
            int num;
            cin >> num;
            dq.push_front(num);
        }
        else if (s == "push_back")
        {
            int num;
            cin >> num;
            dq.push_back(num);
        }
        else if (s == "pop_front")
        {
            if (dq.empty())
                cout << "-1" << '\n';
            else
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (s == "pop_back")
        {
            if (dq.empty())
                cout << "-1" << '\n';
            else
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (s == "size")
        {
            cout << dq.size() << '\n';
        }
        else if (s == "empty")
            cout << dq.empty() << '\n';
        else if (s == "front")
        {
            if (dq.empty())
                cout << "-1" << '\n';
            else
                cout << dq.front() << '\n';
        }
        else if (s == "back")
        {
            if (dq.empty())
                cout << "-1" << '\n';
            else
                cout << dq.back() << '\n';
        }
    }
    
}