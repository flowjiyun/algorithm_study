#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> l;
    string s;
    int n;
    char c;

    cin >> s;
    cin >> n;

    for (int i = 0; i < s.size(); i++)
        l.push_back(s[i]);

    auto cursor = l.end();

    for (int i = 0; i < n; i++)
    {
        cin >> c;

        if (c == 'L')
        {
            if (cursor != l.begin())
                cursor--;
        }

        else if (c == 'D')
        {
            if (cursor != l.end())
                cursor++;
        }

        else if (c == 'B')
        {
            if (cursor != l.begin())
                cursor = l.erase(--cursor);
        }

        else if (c == 'P')
        {
            char ch;
            cin >> ch;
            l.insert(cursor, ch);
        }
    }

    for (auto i : l)
        cout << i;
    return 0;
}