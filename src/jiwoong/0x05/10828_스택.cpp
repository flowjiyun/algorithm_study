#include <iostream>
#include <stack>
using namespace std;

int main(){
    int N;
    cin >> N;
    stack<int> s;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(N--){
        string cmd;
        cin >> cmd;
        if(cmd.compare("push") == 0){
            int ipt;
            cin >> ipt;
            s.push(ipt);
        }
        else if(cmd.compare("top") == 0){
            if(s.empty())
                cout << "-1\n";
            else
                cout << s.top() << "\n";
        }
        else if(cmd.compare("size") == 0){
            cout << s.size() << "\n";
        }
        else if(cmd.compare("empty") == 0){
            cout << s.empty() << "\n";
        }
        else if(cmd.compare("pop") == 0){
            if(s.empty()){
                cout << "-1\n";
            }else{
                cout << s.top() << "\n";
                s.pop();
            }
        }
    }
    return 0;
}