#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, w, L;
vector<int> a;
vector<int> dist;
deque<int> dq;
int main(){
    cin >> n >> w >> L;
    a.resize(n);
    dist.assign(n, 0);
    for(int i = 0 ; i < n; i++) cin >> a[i];
    int passed = 0, nxt = 0, time = 0;
    int curWeight = 0;
    while(passed < n){
        time += 1;
        for(auto & truck : dq){
            dist[truck] += 1;
        }
        if(!dq.empty() && dist[dq.front()] == w + 1){
            passed += 1;
            curWeight -= a[dq.front()];
            dq.pop_front();
        }
        if(nxt < n && curWeight + a[nxt] <= L){
            dq.push_back(nxt);
            dist[nxt] = 1;
            curWeight += a[nxt];
            nxt ++;
        }
        
        // for(auto & d : dist){
        //     cout << d << " ";
        // }
        // cout << endl;
    }
    cout << time;
    return 0;
}