#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int dr[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
int dc[8] = {+1, +2, +2, +1, -1, -2, -2, -1};

bool isValid(int nr, int nc,vector<vector<bool>>& map, int L){
    if(nr < 0 || nr >= L) return false;
    if(nc < 0 || nc >= L) return false;
    if(map[nr][nc] == true) return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    int L, sr, sc, er, ec, r, c, step;
    cin >> T;
    while(T--){
        vector<vector<bool>> map;
        queue<tuple<int, int, int>> q;
        cin >> L;
        map.resize(L);
        for(auto & vec : map){
            vec.assign(L, false);
        }
        cin >> sr >> sc >> er >> ec;
        map[sr][sc] = true;
        q.push(make_tuple(sr, sc, 0));
        while(!q.empty()){
            tie(r, c, step) = q.front();
            q.pop();
            if(r == er && c == ec) {
                cout << step << "\n";
                break;
            }
            for(int i = 0 ; i < 8; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(isValid(nr,nc,map,L)){
                    map[nr][nc] = true;
                    q.push(make_tuple(nr,nc,step + 1));
                }
            }
        }
    }
    return 0;
}