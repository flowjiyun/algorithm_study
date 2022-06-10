#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

#define ID first
#define DIST second
using namespace std;
int N;
vector<vector<int>> map;
vector<vector<pair<int, int>>> distMap;
int dr[] = {-1, 0, +1, 0};
int dc[] = {0, +1, 0, -1};

bool isLand(int nr, int nc){
    if(nr < 0 || nr >= N || nc < 0 || nc >= N) return false;
    return (map[nr][nc] == 1 && distMap[nr][nc].ID == 0);
}

bool isOcean(int nr, int nc){
    if(nr < 0 || nr >= N || nc < 0 || nc >= N) return false;
    return (map[nr][nc] == 0 && distMap[nr][nc].ID == 0);
}

bool isConnected(int nr, int nc, int id){
    if(nr < 0 || nr >= N || nc < 0 || nc >= N) return false;
    return (distMap[nr][nc].ID != 0 && distMap[nr][nc].ID != id);
}


int main(){
    int id = 1;
    queue<pair<int, int>> q;
    queue<pair<int, int>> fq;
    cin >> N;
    map.resize(N);
    distMap.resize(N);
    for(auto & vec : map){
        vec.resize(N);
        for(auto & ele : vec)
            cin >> ele;
    }
    for(auto & vec : distMap){
        vec.assign(N, make_pair(0, 0));
    }
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N ; j++){
            if(map[i][j] == 1 && distMap[i][j].ID == 0){
                distMap[i][j].ID = id;
                q.push(make_pair(i, j));
                while(!q.empty()){
                    auto cur = q.front();
                    bool isEdge = false;
                    q.pop();
                    for(int d = 0 ; d < 4 ; d++){
                        int nr = cur.first + dr[d], nc = cur.second + dc[d];
                        if(isLand(nr, nc)){
                            q.push(make_pair(nr, nc));
                            distMap[nr][nc].ID = id;
                        }else if(isOcean(nr, nc)){
                            isEdge = true;
                        }
                    }
                    if(isEdge) fq.push(make_pair(cur.first, cur.second)); 
                }
                id++;
            }
        }
    }
    vector<int> ans;
    while(!fq.empty()){
        int r, c;
        tie(r, c) = fq.front();
        fq.pop();

        // cout << "\n";
        // for(auto & vec : distMap){
        //     for(auto & ele : vec){
        //         // cout << "( "<< ele.ID << " , " << ele.DIST << " ) ";
        //         cout << ele.DIST << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";

        for(int d = 0 ; d < 4 ;d++){
            int nr = r + dr[d], nc = c + dc[d];
            if(isOcean(nr,nc)){
                fq.push(make_pair(nr, nc));
                distMap[nr][nc] = make_pair(distMap[r][c].ID, distMap[r][c].DIST + 1);
            }else if(isConnected(nr, nc, distMap[r][c].ID)){
                ans.push_back(distMap[r][c].DIST + distMap[nr][nc].DIST);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[0];
    // for(auto ele : ans) cout << ele << endl;
    return 0;
}