#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

#define pos first
#define step second

#define row first
#define col second
#define Pos pair<int,int>
int dr[4] = {0, +1, 0, -1};
int dc[4] = {+1, 0, -1, 0};
vector<string> map;
queue<pair<Pos, int>> q;
int N, M;

int isValid(int nr, int nc){
    if(nr < 0 || nr >= N) return false;
    if(nc < 0 || nc >= M) return false;
    if(map[nr][nc] != '1') return false; // visited
    return true;
}

int main(){
    cin >> N >> M;
    map.resize(N);
    for (auto & str : map){
        cin >> str;
    }
    q.push(make_pair(Pos(0, 0), 1));
    map[0][0] = '2';
    while(!q.empty()){
        pair<Pos ,int> cur = q.front();
        q.pop();
        if (cur.pos.row == (N - 1) && cur.pos.col == (M - 1)){
            cout << cur.step;
            break;
        }
        for(int d = 0 ; d < 4 ;d++){
            int nr = cur.pos.row + dr[d], nc = cur.pos.col + dc[d];
            if(isValid(nr, nc)){
                q.push(make_pair(Pos(nr, nc), cur.step + 1));
                map[nr][nc] = '2';
            }
        }
    }
    return 0;
}