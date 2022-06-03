#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, count = 0;
    cin >> N;
    while (N--)
    {
        stack<char> s;
        string input;
        cin >> input;

        for (auto a : input)
        {
            if (s.empty())
                s.push(a);
            else if (s.top() == a)
                s.pop();
            else
                s.push(a);
        }
        if (s.empty())
            count++;
    }
    cout << count;
}