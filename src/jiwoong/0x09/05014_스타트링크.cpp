#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int F, S, G, U, D;
vector<int> visited;
// S => G : 총 F층
bool isValid(int stair){
    if (stair > F) return false;
    // cout << stair << " : pass over F\n";
    if (stair <= 0) return false;
    // cout << stair << " : pass under 1\n";
    return (visited[stair] == 0);
}

int main(){
    cin >> F >> S >> G >> U >> D;
    queue<int> q;
    vector<int> options;
    options.push_back(U);
    options.push_back(-D);
    visited.assign(F + 1, 0);
    q.push(S);
    visited[S] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if (cur == G) break;
        // for (int i = 0 ; i <= F ; i++){
        //     cout << visited[i];
        //     if (i % 10 == 0) cout << endl; 
        // }
        for (auto option : options){
            if(isValid(cur + option)){
                // cout << cur + option << endl;
                visited[cur + option] = visited[cur] + 1;
                q.push(cur + option);
            }
        }
    }
    if(visited[G] != 0)
        cout << visited[G] - 1;
    else
        cout << "use the stairs";
    return 0;
}