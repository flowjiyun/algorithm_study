#include <iostream>
#include <stack>
using namespace std;

int seq[1000001];
int ans[1000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    stack<int> s;
    s.push(0);
    for (int i = 1; i <= N; i++)
        cin >> seq[i];
    for (int i = N; i >= 1; i--){
        while (!s.empty() && s.top() <= seq[i]){
            s.pop();
        }
        if (s.empty()){
            ans[i] = -1;
        }
        else
            ans[i] = s.top();
        s.push(seq[i]);
    }
    for (int i = 1 ; i <= N; i++)
        cout << ans[i] << " ";
    return 0;
}