#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, L, ipt;
    cin >> N >> L;
    deque<int> seqDq;
    deque<int> minDq;
    minDq.push_back(1234567890);
    for(int i = 1; i <= N ; i++){
        cin >> ipt;
        seqDq.push_back(ipt);
        if(seqDq.size() == L + 1){
            if(seqDq.front() == minDq.front()){
                minDq.pop_front();
            }
            seqDq.pop_front();
        }
        while(!minDq.empty() && minDq.back() > ipt){
            minDq.pop_back();
        }
        minDq.push_back(ipt);
        cout << minDq.front() << " ";
    }
    return 0;
}