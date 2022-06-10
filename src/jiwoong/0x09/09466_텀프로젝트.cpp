#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int ans = n;
        vector<int> nxt(n + 1);
        vector<int> visited(n + 1);
        stack<int> s;
        for(int i = 1 ; i <= n ; i++){
            cin >> nxt[i];
        }
        for(int i = 1; i <= n ; i++){
            if(visited[i] == 0){
                // int loopStart = -1;
                s.push(i);
                while(!s.empty()){
                    int cur = s.top();
                    s.pop();
                    //  for(int l = 1 ; l <= n ; l++){
                    //     cout.width(4);
                    //     cout << l;
                    // }
                    // cout << endl;
                    // for(int l = 1 ; l <= n ; l++){
                    //     cout.width(4);
                    //     cout << visited[l];
                    // }
                    // cout << endl;
                    if(visited[nxt[cur]] == i){ // visited
                        cur = nxt[cur];
                        ans -= 1;
                        visited[cur] = -1;
                        while(visited[nxt[cur]] != -1){
                            cur = nxt[cur];
                            visited[cur] = -1;
                            ans -= 1;
                        }
                    }
                    if(visited[nxt[cur]] == 0){
                        s.push(nxt[cur]);
                        visited[nxt[cur]] = i;
                    }
                   
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}