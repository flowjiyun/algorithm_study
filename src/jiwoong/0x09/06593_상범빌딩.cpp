#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int dl[6] = {+1, -1, 0, 0, 0, 0};
int dr[6] = {0, 0, -1, 0, +1, 0};
int dc[6] = {0, 0, 0, +1, 0, -1};

int L, R, C;
bool isValid(int nl, int nr, int nc, vector<vector<vector<int>>>& cube, vector<vector<string>> & cubeMap){
    if (nl < 0 || nl >= L ||
        nr < 0 || nr >= R ||
        nc < 0 || nc >= C ||
        cubeMap[nl][nr][nc] == '#' ||
        cube[nl][nr][nc] != -1) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> R >> C;
    while(L != 0 && R != 0 && C != 0){
        vector<vector<vector<int>>> cube;
        vector<vector<string>> cubeMap;
        queue<tuple<int, int ,int>> q;
        bool isTrue = false;
        cubeMap.resize(L);
        for(auto & layer : cubeMap){
            layer.resize(R);
            for (auto & str : layer){
                cin >> str;
            }
        }
        cube.resize(L);
        for(auto & layer : cube){
            layer.resize(R);
            for (auto & vec : layer){
                vec.assign(C, -1);
            }
        }
        for(int l = 0 ; l < L ; l++){
            for(int r = 0 ; r < R ; r++){
                for(int c = 0 ; c < C ; c++){
                    if(cubeMap[l][r][c] == 'S'){
                        q.push(make_tuple(l, r, c));
                        cube[l][r][c] = 0;
                        break;
                    }
                }
            }
        }
        while(!q.empty()){
            int l, r, c;
            tie(l, r, c) = q.front();
            // for (auto & layer : cube){
            //     for(auto & row : layer){
            //         for(auto & ele : row){
            //             cout << ele << " ";
            //         }
            //         cout << endl;
            //     }
            //     cout << endl;
            // }
            if(cubeMap[l][r][c] == 'E'){
                isTrue = true;
                cout << "Escaped in " << cube[l][r][c] << " minute(s).\n";
                break;
            }
            
            q.pop();
            for (int d = 0; d < 6; d++){
                int nl = l + dl[d], nr = r + dr[d], nc = c + dc[d];
                if(isValid(nl, nr, nc, cube, cubeMap)){
                    q.push(make_tuple(nl, nr, nc));
                    cube[nl][nr][nc] = cube[l][r][c] + 1;
                }
            }
        }
        if(!isTrue) cout << "Trapped!\n";
        cin >> L >> R >> C;
    }
    return 0;
}