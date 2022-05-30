#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        deque<int> dq;
        string fun, ipts;
        bool isFront = true, success = true;
        int n, i = 0;
        cin >> fun >> n >> ipts;
        int ipt = 0;
        dq.resize(n);
        for(auto ch : ipts){
            if('0' <= ch && ch <= '9'){
                ipt = 10 * ipt + ch - '0';
            }else if(ch != '['){
                dq[i++] = ipt;
                ipt = 0;
            }
        }
        for(int i = 0 ; i < fun.size() && success; i++){
            switch(fun[i]){
                case 'R':
                    isFront = !isFront;
                    break;
                case 'D':
                    if(dq.empty()){
                        cout << "error\n";
                        success = false;
                        break;
                    }
                    if(isFront)
                        dq.pop_front();
                    else
                        dq.pop_back();
                    break;
            }
        }
        if(!success) continue;
        cout << "[";
        while(!dq.empty()){
            if(isFront){
                cout << dq.front();
                dq.pop_front();
            }else{
                cout << dq.back();
                dq.pop_back();
            }
            if(dq.size() != 0)
                cout<<",";
        }
        cout << "]\n";
    }
    return 0;
}