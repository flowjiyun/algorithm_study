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
    int count = 0;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(')
            s.push(input[i]);
        else
        {
            if (input[i - 1] == '(')
            {
                s.pop();
                count += s.size();
            }
            else
            {
                count++;
                s.pop();
            }
        }
    }
    cout << count;
}