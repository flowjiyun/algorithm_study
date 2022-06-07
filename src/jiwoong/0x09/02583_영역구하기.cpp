#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int M, N, K;
vector<vector<int>> map;
int dr[4] = {0, +1, 0, -1};
int dc[4] = {+1, 0, -1, 0};

bool isValid(int nr, int nc){
    if(nr < 0 || nr >= M
     ||nc < 0 || nc >= N) return false;
     return map[nr][nc] == 0;
}
int main(){
    cin >> M >> N >> K;
    map.resize(M);
    for(auto & row : map) row.assign(N, 0);
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i = 0 ; i < K; i++){
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        sy = M - 1 - sy;
        ey = M - 1 - ey;
        for(int r = ey + 1 ; r <= sy; r++){
            for(int c = sx; c < ex; c++){ 
                map[r][c] += 1;
            }
        }
    }
    // for(auto & row : map){
    //     for(auto & col : row)
    //         cout << col << " ";
    //     cout << endl;
    // }
    // cout << endl;
    for(int i = 0 ; i < M; i++){
        for(int j = 0 ; j < N ; j++){
            queue<pair<int, int>> q;
            int temp = 0;
            if (map[i][j] == 0){
                q.push(make_pair(i, j));
                map[i][j] = -1;
                while(!q.empty()){
                    auto cur = q.front();
                    temp++;
                    q.pop();
                    for(int d = 0; d < 4; d++){
                        int nr = cur.first + dr[d],nc = cur.second + dc[d];
                        if(isValid(nr, nc)){
                            map[nr][nc] = -1;
                            q.push(make_pair(nr, nc));
                        }
                    }
                }
                pq.push(temp);                
            }
        }
    }
    cout << pq.size() << "\n";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}