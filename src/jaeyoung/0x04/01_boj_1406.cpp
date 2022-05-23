#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    list<char>str;
    int m;
    int i;
    char cmd;

    cin >> s >> m;
    for (auto c : s)
       str.push_back(c);
    list<char>::iterator end =str.end();
    i = 0;
    while (i < m)
    {
        cin >> cmd;
        if (cmd == 'L')
        {
            if (end !=str.begin())
                end--;
        }
        if (cmd == 'D')
        {
            if (end !=str.end())
                end++;
        }
        if (cmd == 'B')
        {
            if (end != str.begin())
            {
                end--;
                end = str.erase(end);
            }
        }
        if (cmd == 'P')
        {
            cin >> cmd;
            str.insert(end, cmd);
        }
        i++;
    }
    for (auto i : str)
        cout << i;
}