#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> map;
vector<vector<bool>> visited;

bool isValid(int nr, int nc, int criterion){
    if(nr < 0 || nr >= N) return false;
    if(nc < 0 || nc >= N) return false;
    if(visited[nr][nc]) return false;
    return (map[nr][nc] > criterion);
}

int dr[4] = {-1, 0, +1, 0};
int dc[4] = {0, +1, 0, -1};

int main(){
    int temp, ans = 0;
    cin >> N;
    map.resize(N);
    visited.resize(N);
    for(auto & row : map){
        row.resize(N);
    }
    for (int i = 0 ; i < N ; i++){
        visited[i].assign(N, false);
        for(int j = 0 ; j < N ; j++){
            cin >> map[i][j];
        }
    }
    // h : 0 부터 시작... ㄷㄷ
    for (int h = 0 ; h <= 100 ; h++){
        queue<pair<int, int>> q;
        temp = 0;
        for (int i = 0; i < N ; i++){
            for(int j = 0 ; j < N ;j++){
                if(map[i][j] > h && !visited[i][j]){
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                    temp++;
                    while(!q.empty()){
                        auto cur = q.front();
                        q.pop();
                        for(int d = 0; d < 4; d++){
                            int nr = cur.first + dr[d], nc = cur.second + dc[d];
                            if(isValid(nr,nc,h)){
                                q.push(make_pair(nr, nc));
                                visited[nr][nc] = true;
                            }
                        }
                    }
                }
            }
        }
        // cout << h << endl;
        // for(int i = 0 ; i < N ; i++){
        //     for(int j = 0 ; j < N ; j++){
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << temp << endl;
        ans = max(ans, temp);
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                visited[i][j] = false;
            }
        }
    }
    cout << ans;
    return 0;
}