#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    stack<int> S;
    S.push(10);
    S.push(20);
    S.push(30); // 10 20 30
    cout << S.size() << '\n';

    if (S.empty())
        cout << "S is empty\n";
    else
        cout << "S is not empty\n";

    S.pop(); // 10 20
    cout << S.top() << '\n';
    S.pop(); // 10
    cout << S.top() << '\n';
    S.pop(); // empty

    if (S.empty())
        cout << "S is empty\n"; // S is empty
    cout << S.top() << '\n';    // return err 발생

    return 0;
}