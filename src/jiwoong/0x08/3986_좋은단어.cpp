#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int N, ans = 0;
    string ipt;
    cin >> N;
    while(N--){
        stack<char> s;
        cin >> ipt;
        for(char &ch : ipt){
            if (ch == 'A' || ch == 'B'){
                if(!s.empty() && s.top() == ch)
                    s.pop();
                else
                    s.push(ch);
            }
        }
        ans += s.empty();
    }
    cout << ans;
    return 0;
}