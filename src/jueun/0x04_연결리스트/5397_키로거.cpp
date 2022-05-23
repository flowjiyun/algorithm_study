#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    while (n--)
    {
        list<char> l;
        string s;

        cin >> s;

        auto cursor = l.begin();

        for (auto a : s)
        {
            if (a == '<')
            {
                if (cursor != l.begin())
                    cursor--;
            }

            else if (a == '>')
            {
                if (cursor != l.end())
                    cursor++;
            }

            else if (a == '-')
            {
                if (cursor != l.begin())
                    cursor = l.erase(--cursor);
            }
            else
                l.insert(cursor, a);
        }

        for (auto a : l)
            cout << a;
        cout << "\n";
    }
    return 0;
}