#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> space;
bool isValid(int n){
    if(n < 0 || n > 100000) return false;
    return space[n] == -1;
}

int main(){
    int N, K;
    cin >> N >> K;
    space.assign(100001, -1);
    queue<int> q;
    q.push(N);
    space[N] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == K) break;
        if(isValid(2 * cur)){
            q.push(2 * cur);
            space[2 * cur] = space[cur];
        }
        if(isValid(cur - 1)){
            q.push(cur - 1);
            space[cur - 1] = space[cur] + 1;
        }
        if(isValid(cur + 1)){
            q.push(cur + 1);
            space[cur + 1] = space[cur] + 1;
        }
    }
    cout << space[K];
    return 0;
}