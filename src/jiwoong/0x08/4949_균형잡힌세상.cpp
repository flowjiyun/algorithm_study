#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char sen[1024];
    cin.getline(sen, 1024);
    while(sen[0] != '.'){
        stack<char> s;
        bool suc = true;
        for(int i = 0 ; sen[i] != '\0'; i++){
            if(sen[i] == '[' || sen[i] == '(')
                s.push(sen[i]);
            if(sen[i] == ']'){
                if(!s.empty() && s.top() == '[')
                    s.pop();
                else{
                    suc = false;
                    break;
                }
            }
            if(sen[i] == ')'){
                if(!s.empty() && s.top() == '(')
                    s.pop();
                else{
                    suc = false;
                    break;
                }
            }
        }
        if(!s.empty()) suc = false;
        if(suc) cout << "yes\n";
        else cout << "no\n";
        cin.getline(sen, 1024);
    }
    return 0;
}