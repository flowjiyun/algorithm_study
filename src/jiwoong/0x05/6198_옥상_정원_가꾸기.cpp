#include <iostream>
#include <stack>
#include <utility>
using namespace std;
#define VAL first
#define NUM second

int h[80001];

int main(){
    int N;
    long long cnt = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> h[i];
    stack<pair<int ,int>> s;
    s.push(make_pair(0, 0));
    for (int i = N - 1 ; i >= 0 ; i--){
        if (s.top().VAL < h[i]){
            int temp = 0;
            while (!s.empty() && s.top().VAL < h[i]){
                temp += s.top().NUM;
                s.pop();
            }
            if (s.empty()){
                s.push(make_pair(h[i], temp + 1));
            }else{
                if(s.top().VAL == h[i]){
                    s.top().NUM += temp + 1;
                }else{ // VAL > h[i]
                    s.push(make_pair(h[i], temp + 1));
                }
            }
            cnt += temp;
        }else if (s.top().VAL > h[i]){
            s.push(make_pair(h[i], 1));
        }else{
            s.top().NUM += 1;
        }
    }
    cout << cnt;
    return 0;
}