#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    deque<int> dq;
    cin >> N;

    while (N--)
    {
        string com;
        cin >> com;
        if (com == "push_front")
        {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if (com == "push_back")
        {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if (com == "pop_front")
        {
            if (!dq.empty())
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (com == "pop_back")
        {
            if (!dq.empty())
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (com == "size")
        {
            cout << dq.size() << '\n';
        }
        else if (com == "empty")
        {
            if (dq.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (com == "front")
        {
            if (!dq.empty())
            {
                cout << dq.front() << '\n';
            }
            else
                cout << "-1\n";
        }
        else
        {
            if (!dq.empty())
            {
                cout << dq.back() << '\n';
            }
            else
                cout << "-1\n";
        }
    }
}