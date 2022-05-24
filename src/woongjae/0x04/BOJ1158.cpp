#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    struct NODE *prev, *next;
    int data;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    int n;
    int i;
    vector<int> V, ans;

    i = 1;
    cin >> n >> k;
    while (i <= n)
    {
        V.push_back(i);
        i++;
    }
    i = 0;
    while (ans.size() < n)
    {
        if(i % k == k - 1)
            ans.push_back(V[i]);
        else
            V.push_back(V[i]);
        i++;
    }
    i = 0;
    cout << "<";
    while (i < n)
    {
        if (i == n - 1) 
            cout << ans[i];
        else 
            cout << ans[i] << ", ";
        i++;
    }
    cout << ">";
    
}