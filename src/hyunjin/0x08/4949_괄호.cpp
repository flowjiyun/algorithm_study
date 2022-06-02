#include <bits/stdc++.h>
using namespace std;

int isvalid(string str) {
    stack<char> s;
    int i = 0;
    while (str[i] != '.') {
        if (str[i] == '(' || str[i] == '[')
            s.push(str[i]);
        else if (str[i] == ')') {
            if (s.empty() || s.top() != '(') return (1);
            s.pop();
        }
        else if (str[i] == ']') {
            if (s.empty() || s.top() != '[') return (1);
            s.pop();
        }
        i++;
    }
    if (!s.empty()) return (1);
    return (0);
}

int main()
{
    string str;

    while (1) {
        getline(cin, str);
        if (str == ".") break;

        int res = isvalid(str);
        if (res) cout << "no\n";
        else cout << "yes\n";
    }
}
