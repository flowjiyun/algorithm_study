#include <iostream>
#include <stack>
#include <string>
#include <utility>
using namespace std;

char op(char ch){
    switch(ch){
        case '(':
            return ')';
        case ')':
            return '(';
        case '[':
            return ']';
        case ']':
            return '[';
    }
    return '\0';
}


int main(){
    stack<pair<char,int>> s;
    string ipt;
    int ans = 0;
    cin >> ipt;
    for(char &ch : ipt){
        if(ch == '(' || ch == '['){
            s.push(make_pair(ch, 0));
        }else{
            pair<char, int> popped;
            if(!s.empty() && s.top().first == op(ch)){
                popped = s.top();
                s.pop();
                if(popped.second == 0){
                    if(ch == ')') popped.second = 2;
                    else popped.second = 3;
                }else{
                    if(ch == ')') popped.second *= 2;
                    else popped.second *= 3;
                }
            }else{
                ans = 0;
                break;
            }
            if(s.empty()) ans += popped.second;
            else{
                s.top().second += popped.second;
            }
        }
    }
    cout << ans;
    return 0;
}