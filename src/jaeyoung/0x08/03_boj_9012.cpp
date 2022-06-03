#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        for (auto c : s)
        {
            if (c == '(')
                st.push(c);
            else if (!st.empty() && c == ')' && st.top() == '(')
                st.pop();
            else if (st.empty() && c == ')')
                st.push(c);
        }
        if (st.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}