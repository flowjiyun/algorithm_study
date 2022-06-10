#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <utility>
using namespace std;
int N, M;
vector<vector<int>> map;
queue<pair<int, int>> q;

int dr[] = {-1, 0, +1, 0};
int dc[] = {0, +1, 0, -1};

int main(){
    int land = 1, iter = 0;
    cin >> N >> M;
    map.resize(N);
    for(auto & vec : map){
        vec.resize(M);
        for(auto & ele : vec)
            cin >> ele;
    }
    while(land < 2){
        int temp = 0;
        vector<tuple<int, int, int>> delta;
        vector<vector<bool>> visited;
        visited.resize(N);
        for(auto & vec : visited)
            vec.assign(M, false);
        for(int i = 1 ; i < N - 1; i++){
            for(int j = 1; j < M - 1; j++){
                if(map[i][j] && !visited[i][j]){
                    temp++;
                    visited[i][j] = true;
                    // cout <<"temp: " <<temp <<  "\n";
                    q.push(make_pair(i, j));
                    while(!q.empty()){
                        auto cur = q.front();
                        q.pop();
                        int plus = 0;
                        for(int d = 0 ; d < 4; d++){
                            int nr = cur.first + dr[d], nc = cur.second + dc[d];
                            if(!visited[nr][nc] && map[nr][nc]){
                                // cout << nr << " " << nc << " \n";
                                q.push(make_pair(nr, nc));
                                visited[nr][nc] = true;
                            }
                            plus += (map[nr][nc] == 0);
                        }
                        delta.push_back(make_tuple(cur.first, cur.second, plus));
                    }
                }
            }
        }
        if (temp >= 2)
            break;
        if (temp == 0){
            iter = 0;
            break;
        }
        for(auto & ele: delta){
            int r, c, p;
            tie(r, c, p) = ele;
            // cout << r << " " << c << " " << p << " \n";
            map[r][c] -= (map[r][c] >= p)?p:map[r][c];
        }
        // for(auto & vec : map){
        //     for(auto & ele : vec){
        //         cout << ele << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        iter++;
        land = temp;
    }
    cout << iter;
    return 0;
}