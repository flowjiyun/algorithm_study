#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

int N, M, K;
vector<vector<vector<int>>> visited;
vector<string> map;
queue<tuple<int,int,int,bool>> q;
int dr[] = {-1, 0, +1, 0};
int dc[] = {0, +1, 0, -1};

bool isValid(int nr, int nc, int nk, int k){
    if(nr < 0 || nr >= N || nc < 0 || nc >= M) return false;
    return ((map[nr][nc] == k + '0') && visited[nk][nr][nc] == -1);
}

int main(){
    int ans = -1;
    cin >> N >> M >> K;
    map.resize(N);
    for(auto & str: map) cin >> str;
    visited.resize(K + 1);
    for(auto & board : visited){
        board.resize(N);
        for(auto & vec : board){
            vec.assign(M, -1);
        }
    }
    q.push(make_tuple(0, 0, 0, true));
    visited[0][0][0] = 1;
    while(!q.empty()){
        int r, c, k, day;
        tie(r, c, k, day) = q.front();
        q.pop();
        if(r == N - 1 && c == M -1){
            ans = visited[k][r][c];
            break;
        }
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(isValid(nr, nc, k, 0)){
                q.push(make_tuple(nr, nc, k, !day));
                visited[k][nr][nc] = visited[k][r][c] + 1;
            }
            if(k < K && day && isValid(nr, nc, k + 1, 1)){
                q.push(make_tuple(nr, nc, k + 1, !day));
                visited[k + 1][nr][nc] = visited[k][r][c] + 1;
            }
        }
        if(!day){
            q.push(make_tuple(r, c, k, !day));
            visited[k][r][c] += 1;
        }
    }
    cout << ans;
    return 0;
}