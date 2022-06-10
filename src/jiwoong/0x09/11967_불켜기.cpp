#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
int N, M;
int dr[] = {-1, 0, +1, 0};
int dc[] = {0, +1, 0, -1};
vector<pair<int, int>> link[101][101];
queue<pair<int, int>> q;
bool turnOn[101][101];
bool visited[101][101];
bool isValid(int nr, int nc){
    return (1 <= nr && nr <= N && 1 <= nc && nc <= N && !visited[nr][nc]);
}

bool canMove(int nr, int nc){
    return (1 <= nr && nr <= N && 1 <= nc && nc <= N && turnOn[nr][nc]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
        int sr, sc, er, ec;
        cin >> sr >> sc >> er >> ec;
        link[sr][sc].push_back(make_pair(er, ec));
    }
    visited[1][1] = true;
    turnOn[1][1] = true;
    int ans = 1;
    q.push(make_pair(1, 1));
    while(!q.empty()){
        int r, c;
        tie(r, c) = q.front();
        // cout << r << " , " << c << endl;
        q.pop();
        // for(int i = 1; i <= N ; i++){
        //     for(int j = 1 ; j <= N ; j++){
        //         cout << turnOn[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        for(auto & dest : link[r][c]){
            int nr, nc;
            tie(nr, nc) = dest;
            ans += (turnOn[nr][nc] == false);
            turnOn[nr][nc] = true;
        }

        queue<pair<int, int>> smallQ;
        smallQ.push(make_pair(1, 1));
        vector<vector<bool>> smallV;
        //O(N)
        smallV.resize(N + 1);
        for(auto & vec : smallV) vec.assign(N + 1, false);
        smallV[1][1] = true;
        //O(N)
        while(!smallQ.empty()){
            int cr , cc;
            tie(cr, cc) = smallQ.front();
            smallQ.pop();
            for(int d = 0; d < 4; d++){
                int nr = cr + dr[d], nc = cc + dc[d];
                if(canMove(nr, nc) && !smallV[nr][nc]){
                    smallQ.push(make_pair(nr, nc));
                    smallV[nr][nc] = true;
                    if(!visited[nr][nc]) {
                        q.push(make_pair(nr, nc));
                        visited[nr][nc] = true;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}