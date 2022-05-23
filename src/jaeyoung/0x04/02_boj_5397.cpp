#include <iostream>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i;
    int n;

    cin >> n;
    i = 0;
    while (i++ < n)
    {
        list<char> ps = {};
        list<char>::iterator cur = ps.begin();
        string s;

        cin >> s;
        for (auto c : s)
        {
            if (c == '<')
            {
                if (cur != ps.begin())
                    cur--;
            }
            else if (c == '>')
            {
                if (cur != ps.end())
                    cur++;
            }
            else if (c == '-')
            {
                if (cur != ps.begin())
                {
                    cur--;
                    cur = ps.erase(cur);
                }
            }
            else
                ps.insert(cur, c);
        }
        for (auto c : ps)
            cout << c;
        cout << '\n';
    }
}