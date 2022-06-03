#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    stack<char> s;
    int tmp = 1, result = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(')
        {
            s.push(input[i]);
            tmp *= 2;
        }
        else if (input[i] == '[')
        {
            s.push(input[i]);
            tmp *= 3;
        }
        else if (input[i] == ')')
        {
            if (s.empty() || s.top() != '(')
            {
                result = 0;
                break;
            }
            if (input[i - 1] == '(')
            {
                tmp /= 2;
                result += 2 * tmp;
                s.pop();
            }
            else
            {
                tmp /= 2;
                s.pop();
            }
        }
        else
        {
            if (s.empty() || s.top() != '[')
            {
                result = 0;
                break;
            }
            if (input[i - 1] == '[')
            {
                tmp /= 3;
                result += 3 * tmp;
                s.pop();
            }
            else
            {
                tmp /= 3;
                s.pop();
            }
        }
    }
    if (!s.empty())
        result = 0;
    cout << result;
}