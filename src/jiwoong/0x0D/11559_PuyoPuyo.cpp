#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

#define HIGHT 12
#define WIDTH 6

int dx[] = {-1, 0, +1, 0};
int dy[] = {0, +1, 0, -1};
int toRow(int y) { return HIGHT -1 - y;}
vector<string> map;
/*
    대문자 방문 x 소문자 방문 o . 빈칸.
*/

/*
    cordinate : (r, c)  => (x, y) : y = 11 - r [0, 12) , x = c [0, 6)
    from (0, 0) => to (11, 5)
    check blast => 각 col에 대해서 (11, col) 부터 스택에 넣어서 rerender
*/

bool isInside(int x, int y){
    if(x < 0 || x >= WIDTH || y < 0 || y >= HIGHT) return false;
    return true;
}

int dfs(int x, int y, char ch){
    int adj = 1; // 본인
    for(int d = 0 ; d < 4 ; d++){
        int nx = x + dx[d], ny = y + dy[d];
        int nr = toRow(ny);
        if(isInside(nx, ny) && map[nr][nx] == ch){
            // cout << map[nr][nx] << " " << ch << endl;
            map[nr][nx] = map[nr][nx] - 'A' + 'a';
            adj += dfs(nx, ny, ch);
        }
    }
    // for(auto & str: map){
    //     cout << str << endl;
    // }
    // cout << endl;
    return adj;
}

void blast(int x, int y, char ch){
    for(int d = 0; d < 4 ; d++){
        int nx = x + dx[d], ny = y + dy[d];
        int nr = toRow(ny);
        if(isInside(nx, ny) && map[nr][nx] == ch){
            char c = map[nr][nx];
            map[nr][nx] = '.';
            blast(nx, ny, c);
        }        
    }
}



int main(){
    map.resize(HIGHT);
    for(auto & str : map) cin >> str;
    int ans = 0;
    int num;
    do{
        num = 0;
        for(int y = 0; y < HIGHT; y++){
            for(int x = 0 ; x < WIDTH ; x++){
                if('A' <= map[toRow(y)][x] && map[toRow(y)][x] <= 'Z'){
                    char c = map[toRow(y)][x];
                    map[toRow(y)][x] = map[toRow(y)][x] - 'A' + 'a';
                    if (dfs(x, y, c) >= 4){
                        c = map[toRow(y)][x];
                        map[toRow(y)][x] = '.';
                        blast(x, y, c);
                        num += 1;
                    }
                }
            }
        }
        // rerendering
        for(int x = 0 ; x < WIDTH; x++){
            stack<char> s;
            for(int r = 0 ; r < HIGHT; r++){
                if(map[r][x] == '.') continue;
                if('a' <= map[r][x] && map[r][x] <= 'z'){
                    s.push(map[r][x] - 'a' + 'A'); 
                }else{
                    s.push(map[r][x]);
                }
            }
            for(int r = HIGHT - 1; r >= 0 ; r--){
                if(!s.empty()){
                    map[r][x] = s.top();
                    s.pop();
                }else{
                    map[r][x] = '.';
                }            
            }
        }
        ans += (num > 0);
    }while(num != 0);
    cout << ans;
    return 0;
}