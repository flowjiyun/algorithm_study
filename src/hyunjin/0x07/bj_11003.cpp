#include <bits/stdc++.h>
using namespace std;
#define idx first
#define val second

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<pair<int, int>> d;
    int n, l;
    cin >> n >> l;
    
    int num;
    for (int i = 1; i <= n; i++) {
        cin >> num;

        while (!d.empty() && d.back().val > num)
            d.pop_back();

        while (!d.empty() && d.front().idx <= i - l)
            d.pop_front(); 

        d.push_back({i, num});

        cout << d.front().val << " ";
    }
}
