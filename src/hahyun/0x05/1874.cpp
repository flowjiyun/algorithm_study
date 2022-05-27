#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, last = 0;
    stack<int> s;
    string result;

    cin >> n;
    while (n--)
    {
        cin >> x;
        if (x > last)
        {
            while (x > last)
            {
                s.push(++last);
                result += '+';
            }
            s.pop();
            result += '-';
        }
        else
        {
            if (!s.empty())
            {
                if (x < s.top())
                {
                    cout << "NO";
                    return 0;
                }
                s.pop();
                result += '-';
            }
        }
    }
    for (auto i : result)
        cout << i << '\n';
}