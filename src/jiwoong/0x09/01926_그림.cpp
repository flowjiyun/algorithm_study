#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

#define row first
#define col second

int dr[4] = {0, +1, 0, -1};
int dc[4] = {+1, 0, -1, 0};
vector<string> map;
int n, m;

int isValid(int nr, int nc){
    if(nr < 0 || nr >= n) return false;
    if(nc < 0 || nc >= m) return false;
    if(map[nr][nc] != '1') return false; // visited
    return true;
}

queue<pair<int,int>> q;
int maxVal(int a, int b) { return (a > b) ? a : b;}

int main(){
    int maxSize = 0;
    int ans = 0;
    cin >> n >> m;
    map.resize(n);
    for(auto &str : map){
        str.resize(m);
        for(int i = 0 ; i < m; i++)
            cin >> str[i];
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m; j++){
            if(map[i][j] == '1'){
                int temp = 1;
                q.push(make_pair(i, j));
                map[i][j] = '2';
                while(!q.empty()){
                    int r = q.front().row, c = q.front().col;
                    q.pop();
                    for(int d = 0 ; d < 4; d++){
                        int nr = r + dr[d], nc = c + dc[d];
                        if(isValid(nr, nc)){
                            map[nr][nc] = '2';
                            q.push(make_pair(nr, nc));
                            temp++;
                        }
                    }
                }
                ans++;
                maxSize = maxVal(maxSize, temp);
            }
        }
    }
    cout << ans << "\n";
    cout << maxSize << "\n";
    return 0;
}