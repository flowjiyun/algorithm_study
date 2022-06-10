#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
int K, W, H;
vector<vector<vector<int>>> visited;
vector<vector<int>> board;
queue<tuple<int, int, int>> q;

int dr[] = {-1, 0, +1, 0, -2, -1, +1, +2, +2, +1, -1, -2};
int dc[] = {0, +1, 0, -1, +1, +2, +2, +1, -1, -2, -2, -1};

bool isValid(int nr, int nc, int nk){
    if (nk > K) return false;
    if (nr < 0 || nr >= H || nc < 0 || nc >= W) return false;
    return (visited[nk][nr][nc] == -1 && board[nr][nc] == 0);
}

int main(){
    int ans = -1;
    cin >> K >> W >> H;
    visited.resize(K + 1);
    for(auto & map : visited){
        map.resize(H);
        for(auto & vec : map){
            vec.assign(W, -1);
        }
    }
    board.resize(H);
    for(auto & vec : board){
        vec.resize(W);
        for(auto & ele : vec){
            cin >> ele;
        }
    }
    q.push(make_tuple(0, 0, 0));
    visited[0][0][0] = 0;
    while(!q.empty()){
        int r, c, k, d = 0;
        tie(r, c, k) = q.front();
        q.pop();
        if (r == H - 1 && c == W - 1){
            ans = visited[k][r][c];
            break;
        }
        for(; d < 4; d++){
            int nr = r + dr[d], nc = c + dc[d];
            if(isValid(nr, nc, k)){
                q.push(make_tuple(nr, nc, k));
                visited[k][nr][nc] = visited[k][r][c] + 1;
            }
        }
        for(;k < K && d < 12; d++){
            int nr = r + dr[d], nc = c + dc[d];
            if(isValid(nr, nc, k+1)){
                q.push(make_tuple(nr, nc, k + 1));
                visited[k+1][nr][nc] = visited[k][r][c] + 1;
            }
        }
    }
    cout << ans;
    return 0;
}