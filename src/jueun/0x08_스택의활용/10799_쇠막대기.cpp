#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt;
    stack<char> s;
    string str;

    cin >> str;

    cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            s.push('(');

        else if (str[i] == ')' && str[i - 1] == '(')
        {
            s.pop();
            cnt += s.size();
        }

        else
        {
            cnt++;
            s.pop();
        }
    }

    cout << cnt;

    return 0;
}
