#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n, result = 0;
    stack<int> s;
    cin >> k;
    while (k--)
    {
        cin >> n;
        if (n)
            s.push(n);
        else
            s.pop();
    }
    while (!s.empty())
    {
        result += s.top();
        s.pop();
    }
    cout << result;
}