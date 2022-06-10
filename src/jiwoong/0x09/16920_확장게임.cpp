#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, M, P;
int dr[] = {-1, 0, +1, 0};
int dc[] = {0, +1, 0, -1};
vector<tuple<char, int, int>>   init;
vector<string>                  map;
vector<int>                     len;
vector<int>                     ans;
vector<vector<int>>             duration;
queue<pair<int ,int>>           q;

bool isInside(int nr, int nc){
    return (0 <= nr && nr < N && 0 <= nc && nc < M);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> P;
    map.resize(N);
    len.resize(P);
    for(auto & ele : len) cin >> ele;
    for(auto & str : map) cin >> str;
    duration.resize(N);
    for(auto & vec : duration){
        vec.assign(M, -1);
    }
    ans.resize(P);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if('1' <= map[i][j] && map[i][j] <= '9'){
                init.push_back(make_tuple(map[i][j], i, j));
            }
        }
    }
    sort(init.begin(), init.end());
    for(auto & ele : init){
        int r, c;
        char id;
        tie(id, r, c) = ele;
        q.push(make_pair(r, c));
        ans[map[r][c] - '0' - 1] += 1;
        duration[r][c] = len[map[r][c] - '0' - 1];
    }
    while(!q.empty()){
        queue<pair<int, int>> sq;
        int r, c;
        tie(r, c) = q.front();
        duration[r][c] = len[map[r][c] - '0' - 1];
        sq.push(q.front());
        q.pop();
        while(!sq.empty()){
            int r, c;
            tie(r, c) = sq.front();
            sq.pop();
            for(int d = 0 ; d < 4 ; d++){
                int nr = r + dr[d], nc = c + dc[d];
                if(isInside(nr, nc)){
                    if(map[nr][nc] == map[r][c]){
                        if(duration[nr][nc] < duration[r][c] - 1){
                            duration[nr][nc] = duration[r][c] - 1;
                            if(duration[nr][nc] != 0)
                                sq.push(make_pair(nr, nc));
                            else{
                                q.push(make_pair(nr, nc));
                                // duration[nr][nc] = len[map[nr][nc] - '0' - 1];
                            }
                        }
                    }
                    if(map[nr][nc] == '.'){
                        map[nr][nc] = map[r][c];
                        ans[map[r][c] - '0' - 1] += 1;
                        duration[nr][nc] = duration[r][c] - 1;
                        if(duration[nr][nc] != 0)
                            sq.push(make_pair(nr, nc));
                        else{
                            q.push(make_pair(nr, nc));
                            // duration[nr][nc] = len[map[nr][nc] - '0' - 1];
                        }
                    }
                }
            }
            // cout << endl;
            // for(auto & str : map) cout << str << endl;
            // cout << endl;
        }
    }
    for(auto & ele : ans){
        cout << ele << " ";
    }
    return 0;
}