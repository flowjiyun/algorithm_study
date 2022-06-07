#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> dq;
    int N, M;
    cin >> N >> M;
    for(int i = 1 ; i <= N; i++){
        dq.push_back(i);
    }
    int sum = 0;
    for(int i = 1 ; i <= M; i++){
        int ipt;
        cin >> ipt;
        int cursor = 0;
        // cout << "start from : "<< dq[0] << endl;
        while(dq[cursor] != ipt)
            cursor++;
        if(cursor <= dq.size() / 2){
            sum += cursor;
            while(cursor--){
                // cout << "front -> back : " << dq.front() << endl;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }else{
            int r = dq.size() - cursor;
            sum += r ;
            while(r--){
                // cout << "back -> front : "<< dq.back() << endl;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        // cout << "front is " << dq[0] << endl;
        dq.pop_front();
    }
    cout << sum;
    return 0;
}