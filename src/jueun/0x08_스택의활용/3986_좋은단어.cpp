#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cnt;

    cin >> n;

    cnt = 0;
    while (n--)
    {
        string str;
        stack<char> s;

        cin >> str;

        for (auto a : str)
        {
            if (a == 'A')
            {
                if (s.empty())
                    s.push(a);

                else if (s.top() != 'A')
                    s.push(a);

                else
                    s.pop();
            }

            else
            {
                if (s.empty())
                    s.push(a);

                else if (s.top() != 'B')
                    s.push(a);

                else
                    s.pop();
            }
        }

        if (s.empty())
            cnt++;
    }

    cout << cnt;

    return 0;
}
