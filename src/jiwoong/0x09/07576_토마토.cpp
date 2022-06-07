#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
vector<vector<int>> map;
queue<pair<int,int>> q;

int dr[4] = {-1, 0, +1, 0};
int dc[4] = {0, +1, 0, -1};

bool isValid(int nr, int nc){
    if(nr < 0 || nr >= N
     ||nc < 0 || nc >= M) return false;
    return (map[nr][nc] == 0);
}

int main(){
    int ans = 0;
    cin >> M >> N;
    map.resize(N);
    for(auto & row : map){
        row.resize(M);
        for(auto & col : row)
            cin >> col;
    }
    for (int r = 0 ; r < N ; r++)
        for(int c = 0 ; c < M ; c++)
        {
            if(map[r][c] == 1){
                q.push(make_pair(r, c));
            }
        }
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int d = 0 ; d < 4; d++){
            int nr = cur.first + dr[d], nc = cur.second + dc[d];
            if(isValid(nr, nc)){
                map[nr][nc] = map[cur.first][cur.second] + 1;
                q.push(make_pair(nr, nc));
            }
        }
    }
    bool isCorrect = true;
    for(int r = 0 ; r < N  && isCorrect;r++){
        for(int c = 0; c < M ;c++){
            // cout << map[r][c] << " ";
            if(map[r][c] == 0){
                ans = 0;
                isCorrect = false;
                break;
            }else{
                ans = max(ans, map[r][c]);
            }
        }
        // cout << endl;/
    }
    cout << ans - 1;

    return 0;
}