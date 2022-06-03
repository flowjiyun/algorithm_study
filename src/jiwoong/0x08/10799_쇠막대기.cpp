#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    stack<char> s;
    string ipt;
    int    ans = 0;
    bool   charged = true;
    cin >> ipt;
    for(char &ch : ipt){
        if (ch == '('){
            if(!charged) charged = true;
            s.push(ch);
        }
        else{
            if(charged){
                ans += s.size() - 1;
                charged = false;
            }else
                ans += 1;
            s.pop();
        }
    }
    cout << ans;
    return 0;
}