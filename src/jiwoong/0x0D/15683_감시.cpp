#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

#define Dir pair<int,int>
#define ROW first
#define COL second

int N, M, ans, O = 0;
int turnTime[6] = {0, 4, 2, 4, 4, 1};
int dirNum[6] = {0, 1, 2, 2, 3, 4};

vector<vector<int>> map;

class Camera{
private:
    // (+1, 0) => (0, -1) ^ => <-  (x, y) => (y, -x)
    void turnCam(Dir& direction){
        int temp = direction.COL;
        direction.COL = -direction.ROW;
        direction.ROW = temp;
    }

    bool isValid(int r, int c){
        if(r < 0 || r >= N || c < 0 || c >= M) return false;
        return (map[r][c] != 6);
    }
public:
    int id;
    int row;
    int col;
    vector<Dir> dir;
    Camera(int r = -1, int c = -1, int id = 0):row(r), col(c), id(id){
        Dir init(+1, 0);
        dir.resize(dirNum[id]);
        for(auto & side : dir){
            if(id != 2){
                side = init;
                turnCam(init);
            }else{
                side = init;
                turnCam(init);
                turnCam(init);
            }
        }
    }
    void turn(){
        for(auto & side : dir) turnCam(side);
    }
    int render(vector<vector<char>> & test){
        int suc = 0; // # : # (count x) , 0 => # : count
        for(auto & side : dir){
            int nr = row + side.ROW, nc = col + side.COL;
            while(isValid(nr, nc)){
                if(test[nr][nc] != '#' && map[nr][nc] == 0){
                    suc += 1;
                    test[nr][nc] = '#';
                }
                nr += side.ROW;
                nc += side.COL;
            }
        }
        return suc;
    }
};


vector<Camera> cameras;

void render(){
    int cnt = N * M - O;
    vector<vector<char>> test;
    test.resize(N);
    for(auto & vec : test) vec.assign(M, '.');
    for(auto & cam : cameras){
        cnt -= cam.render(test);
    }
    // for(auto & vec : test){
    //     for(auto & ele : vec){
    //         cout << ele << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    ans = min(ans, cnt);
}

void select(int n){
    if(n >= cameras.size()){
        render();
        return;
    }
    // 4번은 돌려야함..
    for(int i = 0 ; i < turnTime[cameras[n].id]; i++){
        cameras[n].turn();
        select(n + 1);
    }
}

int main(){
    cin >> N >> M;
    map.resize(N);
    for(int i = 0; i < N ; i++){
        map[i].resize(M);
        for(int j = 0 ; j < M ; j++){
            cin >> map[i][j];
            if(1 <= map[i][j] && map[i][j] <= 5){
                cameras.push_back(Camera(i, j, map[i][j]));
            }
            if(map[i][j] != 0) O += 1;
        }
    }
    ans = N * M - O;
    select(0);
    cout << ans;
    return 0;
}
// 4^8 * (2^6)  => 2^16 * 2^6 = 2^22 => (2048)^2
// 1 : turn 4
// 2 : turn 2
// 3 : turn 4
// 4 : turn 4
// 5 : turn 1 (skip)
// 6 : 벽
// # : 볼 수 있음

// 각 cctv의 방향설정 => cctv가 볼 수 있는 영역 render
// 성공적으로 # 마킹성공 => N * M에서 빼기 (cctv 인 지역도 #으로 해야 볼 수 있는거임) && #이 아닌 거 세기