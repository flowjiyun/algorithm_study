#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> L;
    string init;
    int n;
    char com, c;

    cin >> init;
    for (int i = 0; i < init.size(); i++)
        L.push_back(init[i]);

    auto cursor = L.end();

    cin >> n;
    while (n--)
    {
        cin >> com;
        if (com == 'P')
        {
            cin >> c;
            L.insert(cursor, c);
        }
        else if (com == 'L')
        {
            if (cursor != L.begin())
                cursor--;
        }
        else if (com == 'D')
        {
            if (cursor != L.end())
                cursor++;
        }
        else
        {
            if (cursor != L.begin())
            {
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }
    for (auto i : L)
        cout << i;
}
