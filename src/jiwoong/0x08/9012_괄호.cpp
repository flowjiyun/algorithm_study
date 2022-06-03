#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    string ipt;
    while (T--){
        stack<char> s;
        bool suc = true;
        cin >> ipt;
        for (auto & ch : ipt){
            if(ch == '(' || ch == '[')
                s.push(ch);
            if(ch == ')'){
                if(!s.empty() && s.top() == '(')
                    s.pop();
                else{
                    suc = false;
                    break;
                }
            }
            if(ch == ']'){
                if(!s.empty() && s.top() == '[')
                    s.pop();
                else{
                    suc = false;
                    break;
                }
            }
        }
        if(!s.empty()) suc = false;
        if(suc) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}