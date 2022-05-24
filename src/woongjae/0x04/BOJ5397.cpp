#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    
    cin >> n;
    list<char> L;
    
    while (n--)
    {
        list<char> L = {};
        auto cursor = L.begin();

        string password;
        cin >> password;

        for (auto c : password)
        {
            if (c == '<')
            {
                if (cursor != L.begin())
                    cursor--;
            }
            else if (c == '>')
            {
                if (cursor != L.end())
                    cursor++;
            }
            else if (c == '-')
            {
                if (cursor != L.begin())
                {
                    cursor--;
                    cursor = L.erase(cursor);
                }
            }
            else
                L.insert(cursor, c);
        }
        for (auto c : L)
        {

            cout << c;
        }
        cout << '\n';
    }
    return (0);
}