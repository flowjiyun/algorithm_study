#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    queue<int> q;
    while (N--){
        string cmd;
        cin >> cmd;
        if (cmd == "push"){
            int ipt;
            cin >> ipt;
            q.push(ipt);
        }else if(cmd == "front"){
            if(!q.empty())
                cout << q.front() << "\n";
            else
                cout << "-1\n";
        }else if(cmd == "back"){
            if(!q.empty())
                cout << q.back() << "\n";
            else
                cout << "-1\n";
        }else if(cmd == "empty"){
            cout << q.empty() << "\n";
        }else if(cmd == "pop"){
            if (!q.empty()){
                cout << q.front() << "\n";
                q.pop();
            }else
                cout << "-1\n";
        }else if (cmd == "size"){
            cout << q.size() << "\n";
        }
    }
    return 0;
}