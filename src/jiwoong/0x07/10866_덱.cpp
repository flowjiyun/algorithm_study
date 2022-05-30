#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    deque<int> dq;
    int N;
    cin >> N;
    while(N--){
        string cmd;
        int ipt;
        cin >> cmd;
        if(cmd == "push_back"){
            cin >> ipt;
            dq.push_back(ipt);
        }else if(cmd == "push_front"){
            cin >> ipt;
            dq.push_front(ipt);
        }else if(cmd == "pop_front"){
            if(dq.empty())
                cout << "-1\n";
            else{
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }else if(cmd == "pop_back"){
            if(dq.empty())
                cout << "-1\n";
            else{
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }else if(cmd == "size"){
            cout << dq.size() << "\n";
        }else if(cmd == "empty"){
            cout << dq.empty() << "\n";
        }else if(cmd == "front"){
            if(dq.empty())
                cout << "-1\n";
            else{
                cout << dq.front() << "\n";
            }
        }else if(cmd == "back"){
            if(dq.empty())
                cout << "-1\n";
            else{
                cout << dq.back() << "\n";
            }
        }
    }
    return 0;
}