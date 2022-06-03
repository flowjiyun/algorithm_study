#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> s;
    string str;
    int i;
    int num = 1, sum = 0;

    cin >> str;
    i = 0;
    while (i < str.size())
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
            num *= 2;
        }
        else if (str[i] == ')')
        {
            if (s.empty() || s.top() != '(')
                {
                    cout << "0";
                    return (0);
                }
            else if (str[i - 1] == '(')
                sum += num;
            s.pop();
            num /= 2;
        }
        else if (str[i] == '[')
        {
            s.push(str[i]);
            num *= 3;
        }
        else if (str[i] == ']')
        {
            if (s.empty() || s.top() != '[')
                {
                    cout << "0";
                    return (0);
                }
            else if (str[i - 1] == '[')
                sum += num;
            s.pop();
            num /= 3;
        }
        i++;
    }
    if (s.empty())
        cout << sum;
    else 
        cout << "0";
}