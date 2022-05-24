#include <iostream>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    list<int> L;

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        L.push_back(i);

    auto cur = L.begin();
    cout << '<';
    while (L.size() > 1)
    {
        for (int i = 0; i < k - 1; i++)
        {
            cur++;
            if (cur == L.end())
                cur = L.begin();
        }

        cout << *cur << ',';

        cur = L.erase(cur);
        if (cur == L.end())
            cur = L.begin();
    }
    cout << *cur << '>';
}