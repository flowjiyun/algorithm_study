#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    int k;
    int i;
    int x;
    int sum;

    sum = 0;
    cin >> k;
    i = 0;
    while (i < k)
    {
        cin >> x;
        if (x != 0)
            s.push(x);
        else
            s.pop();
        i++;
    }
    i = s.size();
    while (i--)
    {
        sum += s.top();
        s.pop();
    }
    cout << sum;
}