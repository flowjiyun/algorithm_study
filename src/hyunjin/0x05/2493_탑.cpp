#include <bits/stdc++.h>
using namespace std;
int n, tar;
stack<int> h, idx;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    idx.push(0);
    for (int i = 1; i <= n; i++) {
        cin >> tar;

        while (!h.empty() && h.top() < tar) {
            h.pop();
            idx.pop();
        }

        cout << idx.top() << " ";
        h.push(tar);
        idx.push(i);
    }
}
