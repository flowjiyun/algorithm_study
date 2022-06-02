#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    int result;
    int i;
    stack<char> S;

    i = 0 ;
    result = 0;
    cin >> str;
    while (str[i])
    {
        if (str[i] == '(')
            S.push(str[i]);
        else if (str[i] == ')' && str[i - 1] == '(')
        {
            S.pop();
            result += S.size();
        }
        else
        {
            result++;
            S.pop();
        }
        i++;
    }
    cout << result;
}