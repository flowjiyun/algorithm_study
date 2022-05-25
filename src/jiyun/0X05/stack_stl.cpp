#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;
    s.push(10); // {10}
    s.push(20); // {10, 20}
    s.push(30); // {10, 20, 30}
    cout << s.size() << '\n'; // 3
    if (s.empty())
        cout << "stack is empty" << '\n';
    else
        cout << "stack is not empty" << '\n';
    s.pop(); // {10, 20}
    cout << s.top() << '\n';
    s.pop(); // {10}
    cout << s.top() << '\n';
    s.pop(); // empty
    if (s.empty())
        cout << "stack is empty" << '\n';
    else
        cout << "stack is not empty" << '\n';
    return (0);
}