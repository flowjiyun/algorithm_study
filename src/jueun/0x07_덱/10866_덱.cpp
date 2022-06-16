#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> d;
    string str;
    int n;

    cin >> n;
    while (n--)
    {
        cin >> str;

        if (str == "push_front")
        {
            int m;
            cin >> m;
            d.push_front(m);
        }

        else if (str == "push_back")
        {
            int m;
            cin >> m;
            d.push_back(m);
        }

        else if (str == "pop_front")
        {
            if (d.empty())
                cout << "-1\n";
            else
            {
                cout << d.front() << "\n";
                d.pop_front();
            }
        }

        else if (str == "pop_back")
        {
            if (d.empty())
                cout << "-1\n";
            else
            {
                cout << d.back() << "\n";
                d.pop_back();
            }
        }

        else if (str == "size")
            cout << d.size() << "\n";

        else if (str == "empty")
            cout << d.empty() << "\n";

        else if (str == "front")
        {
            if (d.empty())
                cout << "-1\n";
            else
                cout << d.front() << "\n";
        }

        else if (str == "back")
        {
            if (d.empty())
                cout << "-1\n";
            else
                cout << d.back() << "\n";
        }
    }

    return 0;
}