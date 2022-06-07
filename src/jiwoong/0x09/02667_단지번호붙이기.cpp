#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int N; 
priority_queue<int,vector<int>, greater<int>> ans;
vector<string> map;
int dr[4] = {0, +1, 0, -1};
int dc[4] = {+1, 0, -1, 0};
bool isValid(int nr, int nc){
    if(nr < 0 || nr >= N
     ||nc < 0 || nc >= N) return false;
     return (map[nr][nc] == '1');
}

int main(){
    cin >> N;
    map.resize(N);
    for(auto & str : map)
        cin >> str;
    for (int i = 0 ; i < N ; i++){
        for(int j = 0; j < N ; j++){
            queue<pair<int, int>> q;
            if(map[i][j] == '1'){
                int temp = 0;
                q.push(make_pair(i,j));
                map[i][j] = '2';
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    temp++;
                    for(int d = 0; d < 4; d++){
                        int nr = cur.first + dr[d], nc = cur.second + dc[d];
                        if(isValid(nr, nc)){
                            q.push(make_pair(nr, nc));
                            map[nr][nc] = '2';
                        }
                    }
                }
                ans.push(temp);
            }
        }
    }
    cout << ans.size() << "\n";
    while(!ans.empty()){
        cout << ans.top() << endl;
        ans.pop();
    }
    return 0;
}