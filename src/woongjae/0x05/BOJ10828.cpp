#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int data;
    string s;
    stack<int> st;

    cin >> n;
    while (n--)
    {
        cin >> s;
        if(s == "push")
        {
            cin >> data;
            st.push(data);
        }
        else if (s == "pop")
        {
            if (st.empty())
                cout << "-1" << '\n';
            else
            {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (s == "size")
        {
            cout << st.size() << '\n';
        }
        else if (s == "empty")
        {
            if (st.empty())
                cout << "1" << '\n';
            else
                cout << "0" << '\n';
        }
        else if (s == "top")
        {
            if (st.empty())
                cout << "-1" << '\n';
            else
                cout << st.top() << '\n';
        }
    }
}