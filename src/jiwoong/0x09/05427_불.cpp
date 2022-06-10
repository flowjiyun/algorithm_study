#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int w, h;
int dr[4] = {-1, 0, +1, 0};
int dc[4] = {0, +1, 0, -1};

bool canMove(int nr, int nc, vector<string>& map){
    if(nr < 0 || nr >= map.size()) return false;
    if(nc < 0 || nc >= map[0].size()) return false;
    if(map[nr][nc] != '.') return false;
    return true;
}

bool canBurn(int nr, int nc, vector<string>& map){
    if(nr < 0 || nr >= map.size()) return false;
    if(nc < 0 || nc >= map[0].size()) return false;
    if(map[nr][nc] == '#' || map[nr][nc] == '*') return false;
    return true;
}

bool canEscape(int r, int c, vector<string>& map){
    if(r == 0 || r == map.size() - 1 || c == 0 || c == map[0].size() - 1)
        return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, r, c, step;
    cin >> T;
    while(T--){
        vector<string> map;
        queue<tuple<int,int,int>> q;
        int tr, tc;
        int ans = 0;
        cin >> w >> h;
        map.resize(h);
        for(auto & str: map)
            cin >> str;
        for(int i = 0 ; i < h; i++){
            for(int j = 0 ; j < w ; j++){
                if(map[i][j] == '*'){
                    q.push(make_tuple(i, j, -1));
                }else if(map[i][j] == '@'){
                    tr = i;
                    tc = j;
                }
            }
        }
        q.push(make_tuple(tr, tc, 1));
        while(!q.empty()){
            tie(r, c, step) = q.front();
            q.pop();
            if(step > 0 && canEscape(r,c,map)){
                ans = step;
                break;
            }
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(step == -1){
                    if(canBurn(nr,nc, map)){
                        map[nr][nc] = '*';
                        q.push(make_tuple(nr,nc,-1));
                    }
                }else{
                    if(canMove(nr,nc, map)){
                        map[nr][nc] = '@';
                        q.push(make_tuple(nr,nc,step + 1));
                    }
                }
            }
        }
        if(ans != 0) cout << ans << "\n";
        else cout << "IMPOSSIBLE\n";
    }

    return 0;
}