#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

#define ROW first
#define COL second
int N, M, K;
vector<vector<int>> map;

void turnClockwise(vector<pair<int, int>>& matrix, int& R, int& C){
    int mr = 1000, mc = 1000;
    int temp;
    for(auto & pos : matrix){
        int nr = pos.COL;
        int nc = max(R, C) - pos.ROW;
        mr = min(mr, nr);
        mc = min(mc, nc);
        pos.ROW = nr;
        pos.COL = nc;
    }
    for(auto & pos : matrix){
        pos.ROW -= mr;
        pos.COL -= mc;
    }
    temp = R;
    R = C;
    C = temp;
}

bool canFit(int sr, int sc, vector<pair<int, int>> & poses){
    for(auto & cord : poses){
        int nr = sr + cord.ROW,  nc = sc + cord.COL;
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) return false;
        if(map[sr + cord.ROW][sc + cord.COL] == 1){
            return false;
        }
    }
    return true;
}

void printVis(){
    for(auto & vec : map){
        for(auto & ele : vec){
            cout << ele << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

void printPoses(vector<pair<int, int>> poses, int R, int C){
    sort(poses.begin(), poses.end());
    int p = 0;
    for(int i = 0; i <= R; i++){
        for(int j = 0 ; j <= C ; j++){
            if(i == poses[p].ROW && j == poses[p].COL){
                cout << "1 ";
                p++;
            }else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << "\n\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin >> N >> M >> K;
    map.resize(N);
    for(auto & vec : map){
        vec.assign(M, 0);
    }
    for(int i = 0 ; i < K ; i++){
        bool suc = false;
        int R, C, P = 0;
        cin >> R >> C;
        vector<pair<int, int>> poses;
        poses.resize(R*C);
        for(int r = 0 ; r < R ; r++){
            for(int c = 0 ; c < C; c++){
                int ipt;
                cin >> ipt;
                if(ipt == 1){ 
                    poses[P++] = make_pair(r, c);
                }
            }
        }
        R -= 1;
        C -= 1;
        poses.resize(P);
        // printVis();
        for(int t = 0 ; t < 4 && !suc; t++){
            for(int r = 0 ; r < N && !suc; r++){
                for(int c = 0 ; c < M ; c++){
                    if(canFit(r, c, poses)){
                        for(auto & cord : poses){
                            map[r + cord.ROW][c + cord.COL] = 1;
                        }
                        suc = true;
                        ans += poses.size();
                        // printPoses(poses, R, C);
                        break;
                    }
                }
            }
            if(!suc) turnClockwise(poses, R, C);
            // sort(poses.begin(), poses.end());
        }
    }
    cout << ans;

    return 0;
}