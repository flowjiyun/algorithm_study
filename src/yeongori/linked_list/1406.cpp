#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    list<char> L;
    int cnt;
    char cmd;

    cin >> str >> cnt;
    for (auto c : str)
        L.push_back(c);
    auto cur = L.end();

    for (int i = 0; i < cnt; i++)
    {
        cin >> cmd;
        if (cmd == 'P')
        {
            char c;
            cin >> c;
            L.insert(cur, c);
        }
        else if (cmd == 'B')
        {
            if (cur != L.begin())
            {
                cur--;
                cur = L.erase(cur);
            }
        }
        else if (cmd == 'L')
        {
            if (cur != L.begin())
                cur--;
        }
        else if (cmd == 'D')
        {
            if (cur != L.end())
                cur++;
        }
    }

    for (auto l : L)
        cout << l;
    return (0);
}