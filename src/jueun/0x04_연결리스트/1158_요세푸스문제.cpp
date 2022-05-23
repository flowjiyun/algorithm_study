#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, cnt;
    list<int> l;

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        l.push_back(i);

    cnt = 1;
    cout << "<";
    while (!l.empty())
    {
        if (cnt == k)
        {
            cout << l.front();
            l.pop_front();
            cnt = 0;
            if (l.empty())
                cout << ">";
            else
                cout << ", ";
        }
        else
        {
            l.push_back(l.front());
            l.pop_front();
        }
        cnt++;
    }

    return 0;
}