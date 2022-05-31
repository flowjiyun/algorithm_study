#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    queue<int> q;
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        q.push(i);
    }

    int temp;
    while (q.size() > 1) {
        q.pop();
        temp = q.front();
        q.pop();
        q.push(temp);
    }

    cout << q.front();
}
