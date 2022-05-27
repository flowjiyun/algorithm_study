#include <iostream>
#include <stack>
using namespace std;

int h[500001];
int ans[500001];
int main(){
    int N;
    h[0] = 1234567890;
    cin >> N;
    stack<int> s;
    for (int i = 1 ; i <= N; i++)
        cin >> h[i];
    s.push(0);
    for (int i = 1 ; i <= N ; i++){
        if( h[s.top()] > h[i]){
            ans[i] = s.top();
            s.push(i);
        }else{ // h[s.top()] < h[i]
            while (h[s.top()] < h[i]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
    }
    for (int i = 1 ; i <= N; i++){
        cout << ans[i] << " ";
    }
    return 0;
}