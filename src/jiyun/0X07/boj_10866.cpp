#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> D;
    string cmd;
    int nb;
    cin >> nb;
    while (nb--)
    {
        cin >> cmd;
        if (cmd == "push_front")
        {
            int data;
            cin >> data;
            D.push_front(data);   
        }
        else if (cmd == "push_back")
        {
            int data;
            cin >> data;
            D.push_back(data);
        }
        else if (cmd == "pop_front")
        {
            if (D.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << D.front() << '\n';
                D.pop_front();
            }
        }
        else if (cmd == "pop_back")
        {
            if (D.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << D.back() << '\n';
                D.pop_back();
            }
        }
        else if (cmd == "size")
        {
            cout << D.size() << '\n';
        }
        else if (cmd == "empty")
        {
            if (D.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (cmd == "front")
        {
            if (D.empty())
                cout << -1 << '\n';
            else
                cout << D.front() << '\n';
        }
        else
        {
            if (D.empty())
                cout << -1 << '\n';
            else
                cout << D.back() << '\n';
        }
    }
    return (0);
}