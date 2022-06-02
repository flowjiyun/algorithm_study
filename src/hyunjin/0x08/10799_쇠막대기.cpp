#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str;
    cin >> str;

    stack<char> s;
    int cnt = 0, i = 0;
    while (str[i]) {
        while (str[i] == '(') {
            s.push(str[i++]);
        }
        
        s.pop();
        if (!s.empty()) cnt += s.size();

        while (str[++i] == ')') {
            cnt++;
            s.pop();
        }
    }

    cout << cnt;
}
