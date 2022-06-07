#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<string> map;
vector<string> map2;
int dr[4] = {0, +1, 0, -1};
int dc[4] = {+1, 0, -1, 0};
bool isValid(int nr, int nc, char ori){
    if(nr < 0 || nr >= N) return false;
    if(nc < 0 || nc >= N) return false;
    if(map[nr][nc] != ori) return false;
    return true;
}

bool isValid2(int nr, int nc, char ori){
    if(nr < 0 || nr >= N) return false;
    if(nc < 0 || nc >= N) return false;
    if(ori == 'B' && map2[nr][nc] != ori) return false;
    else if((ori == 'R' || ori == 'G') && (map2[nr][nc] == '.' || map2[nr][nc] == 'B')) return false;
    return true;
}

void print(){
    for(auto & str: map){
        cout << str << endl;
    }
    cout << endl;
}

void print2(){
    for(auto & str: map2){
        cout << str << endl;
    }
    cout << endl;
}

int main(){
    int ans[2] = {0};
    cin >> N;
    map.resize(N);
    for(auto & str: map){
        cin >> str;
    }
    map2 = map;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(map[i][j] != '.'){
                queue<pair<int,int>> q;
                char ori = map[i][j];
                q.push(make_pair(i ,j));
                map[i][j] = '.';
                ans[0] += 1;
                while(!q.empty()){
                    pair<int,int> cur = q.front();
                    q.pop();
                    // print();
                    for(int d = 0; d < 4 ;d++){
                        int nr = cur.first + dr[d] , nc = cur.second + dc[d];
                        if(isValid(nr,nc, ori)){
                            q.push(make_pair(nr,nc));
                            map[nr][nc] = '.';
                        }
                    }
                }
            }
            if(map2[i][j] != '.'){
                queue<pair<int,int>> q;
                char ori = map2[i][j];
                q.push(make_pair(i,j));
                map2[i][j] = '.';
                ans[1] += 1;
                while(!q.empty()){
                    pair<int,int> cur = q.front();
                    q.pop();
                    // print2();
                    for(int d = 0; d < 4 ;d++){
                        int nr = cur.first + dr[d] , nc = cur.second + dc[d];
                        if(isValid2(nr,nc, ori)){
                            q.push(make_pair(nr,nc));
                            map2[nr][nc] = '.';
                        }
                    }
                }
            }
        }
    }
    cout << ans[0] << " " << ans[1];
    return 0;
}