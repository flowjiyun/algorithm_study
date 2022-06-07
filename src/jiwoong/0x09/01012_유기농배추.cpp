#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dr[4] = {-1, 0, +1, 0};
int dc[4] = {0, +1, 0, -1};

bool isValid(int nr, int nc, int N, int M, vector<vector<int>> &map){
    if(nr < 0 || nr >= N
     ||nc < 0 || nc >= M) return false;
     return (map[nr][nc] == 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N, M, K, ans = 0;
        vector<vector<int>> map;
        queue<pair<int, int>> q;
        cin >> M >> N >> K;
        map.resize(N);
        for(auto & row : map) row.resize(M);
        for(int i = 0; i < K ; i++){
            int R, C;
            cin >> C >> R;
            map[R][C] = 1;
        }
        for (int r = 0 ; r < N ; r++){
            for(int c= 0; c < M ;c++){
                if(map[r][c] == 1){
                    q.push(make_pair(r, c));
                    map[r][c] = 2;
                    ans += 1;
                    while(!q.empty()){
                        auto cur = q.front();
                        q.pop();
                        for(int d = 0 ; d < 4 ;d++){
                            int nr = cur.first + dr[d], nc = cur.second + dc[d];
                            if(isValid(nr, nc, N, M, map)){
                                map[nr][nc] = 2;
                                q.push(make_pair(nr, nc));
                            }
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}