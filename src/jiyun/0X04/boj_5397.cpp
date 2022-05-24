#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int nb;
    cin >> nb;

    while(nb--)
    {
        list<char> l;
        auto cursor = l.begin();

        string password;
        cin >> password;
        for (auto c : password)
        {
            if (c == '<')
            {
                if (cursor != l.begin())
                    cursor--;
            }
            else if (c == '>')
            {
                if (cursor != l.end())
                    cursor++;
            }
            else if (c == '-')
            {
                if (cursor != l.begin())
                {
                    cursor--;
                    cursor = l.erase(cursor);
                }
            }
            else
            {
                l.insert(cursor, c);
            }
        }
        for (auto c : l)
            cout << c;
        cout << '\n';
    }
    return(0);
}