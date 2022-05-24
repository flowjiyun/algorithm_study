#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        list<char> L;
        auto cursor = L.end();

        string str;
        cin >> str;
        for (auto i : str)
        {
            if (i == '<')
            {
                if (cursor != L.begin())
                    cursor--;
            }
            else if (i == '>')
            {
                if (cursor != L.end())
                    cursor++;
            }
            else if (i == '-')
            {
                if (cursor != L.begin())
                {
                    cursor--;
                    cursor = L.erase(cursor);
                }
            }
            else
            {
                L.insert(cursor, i);
            }
        }
        for (auto i : L)
            cout << i;
        cout << '\n';
    }
}