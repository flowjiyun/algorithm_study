#include <iostream>
#include <stack>
#include <utility>
using namespace std;

long long h[500005];
#define VAL first
#define NUM second
#define DEBUG

int main(){
    int N;
    cin >> N;
    for (int i = 0 ; i < N; i++){
        cin >> h[i];
    }
    h[N] = -1;
    // cout << endl;

    stack<pair<long long, int>> s;
    long long o, n ;
    long long ans = 0;
    s.push(make_pair(h[0], 1));
    pair<long long,int> popped;
    for (int i = 1 ; i < N ; i++){
        if(s.top().VAL != h[i - 1])
            ans++;
        if(s.top().VAL > h[i]){
            ans++;
            s.push(make_pair(h[i], 1));
        }else if(s.top().VAL == h[i]){
            // if(s.top().VAL == h[i - 1])
            //     ans--;
            ans += s.top().NUM;
            if(s.size() > 1)
                ans++;
            s.top().NUM += 1;
        }else{
            while(!s.empty() && s.top().VAL < h[i]){
                ans += s.top().NUM;
                s.pop();
            }
            if (s.empty()){
                s.push(make_pair(h[i], 1));
            }else{
                if(s.top().VAL == h[i]){
                    ans += s.top().NUM;
                    if(s.size() > 1)
                        ans++;
                    s.top().NUM++;
                }else{
                    ans++;
                    s.push(make_pair(h[i], 1));
                }
            }
        }
        // cout << i <<"(" << h[i] << ") " << ans << endl;
    }


    // for (int i = 1; i <= N; i++){
    //     int cnt = 0;
    //     o = h[i - 1];
    //     n = h[i];
    //     #ifdef DEBUG
    //         cout << o << " " << n << endl;
    //     #endif
    //     if(i != N)
    //         cnt++;
    //     #ifdef DEBUG
    //         cout << "before o > n "<< cnt << endl;
    //     #endif
    //     if(o >= n){
    //         #ifdef DEBUG
    //             cout << "After o > n\n";
    //         #endif

    //         if(!s.empty()) {
    //             pair<long long,int> poped;
    //             cout << "Before popping\n";
    //             while((!s.empty()) && s.top().VAL <= o){
    //                 // cout << s.top().VAL << " " << s.top().NUM << endl;
    //                 poped = s.top();
    //                 cnt += s.top().NUM;
    //                 s.pop();
    //                 if (!s.empty()) cnt += 1;
    //             }
    //             #ifdef DEBUG
    //                 cout << "After poping " << cnt << "\n";
    //             #endif

    //             #ifdef DEBUG
    //                 cout << "After empty check " << cnt << "\n";
    //             #endif
                
    //             if (poped.VAL == n){
    //                 poped.NUM += 1;
    //                 s.push(poped);
    //             }else{
    //                 s.push(make_pair(o, 1));
    //             }
    //         }
    //         else{
    //             s.push(make_pair(o, 1));
    //         }
    //     }else{
    //         if(s.top().VAL == o){
    //             cnt += s.top().VAL - 1 + 1;
    //             s.top().NUM += 1;
    //         }
    //     }
    //     #ifdef DEBUG    
    //         cout << "final " << cnt << endl;
    //     #endif

    //     ans += cnt;
    //     // #ifdef DEBUG        
    //     //     cout << h[i] <<" "<< cnt << endl;
    //     // #endif
    // }

    cout << ans;
    return 0;
}