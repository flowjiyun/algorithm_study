#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define Pos pair<int, int>
#define row first
#define col second

#define pos first
#define step second

int R,C;
vector<string> map;
queue<pair<Pos, int>> q;
int dr[4] = {0, +1, 0, -1};
int dc[4] = {+1, 0, -1, 0};

bool canBurn(int nr, int nc){
    if(nr < 0 || nr >= R) return false;
    if(nc < 0 || nc >= C) return false;
    if(map[nr][nc] == '#'||
       map[nr][nc] == 'F') return false;
    return true;
}

bool canMove(int nr, int nc){
    if(nr < 0 || nr >= R) return false;
    if(nc < 0 || nc >= C) return false;
    if(map[nr][nc] != '.') return false;
    return true;
}

bool canEscape(int r, int c){
    if((r == 0 || r == R - 1) || (c == 0 || c == C - 1)) return true;
    else return false;
}

void print(){
    for (auto & str : map){
        cout << str << endl;
    }
    cout << endl;
}

int main(){
    bool suc = false;
    cin >> R >> C;
    map.resize(R);
    for(auto & str: map){
        cin >> str;
    }
    int r, c;
    for(int i = 0 ; i < R; i++){
        for(int j = 0 ; j < C; j++){
            if(map[i][j] == 'F'){
                q.push(make_pair(Pos(i, j) ,-1));
            }else if(map[i][j] == 'J'){
                r = i;
                c = j;
            }
        }
    }
    q.push(make_pair(Pos(r, c), 1));
    while(!q.empty()){
        pair<Pos, int> cur = q.front();
        q.pop();
        // print();
        if(cur.step > 0 && canEscape(cur.pos.row, cur.pos.col)){
            suc = true;
            cout << cur.step;
            break;
        }
        if(cur.step == -1){
            for (int d = 0 ; d < 4 ; d++){
                int nr = cur.pos.row + dr[d], nc = cur.pos.col + dc[d];
                if(canBurn(nr, nc)){
                    q.push(make_pair(Pos(nr,nc), -1));
                    map[nr][nc] = 'F';
                }
            }
        }else{
            for (int d = 0 ; d < 4 ; d++){
                int nr = cur.pos.row + dr[d], nc = cur.pos.col + dc[d];
                if(canMove(nr, nc)){
                    q.push(make_pair(Pos(nr,nc), cur.step + 1));
                    map[nr][nc] = 'J';
                }
            }
        }
    }
    if(!suc) cout << "IMPOSSIBLE";
    return 0;
}