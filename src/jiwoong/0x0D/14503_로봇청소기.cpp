#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

int N, M, R, C ,D;
vector<vector<int>> map;
int dr[] = {-1, 0, +1, 0};
int dc[] = {0, +1, 0 ,-1};
/*
    0 북  dr[d] -1
    1 동  dc[d] +1
    2 남  dr[d] +1
    3 서  dc[d] -1

    1.  현재 위치를 청소
    2.  A.  현재 위치 기준 왼쪽에 청소하지 않은 공간 O => 회전 / 전진 / 1번
        B.  청소한 칸O : TURN LEFT / 전진 => 4번연속시 후진... 벽이라면 멈춰
            청소한 칸X : 청소하고 2번
*/
int turnLeft(const int& dir){
    return (4 + dir - 1) % 4;
}

bool isValid(int nr, int nc){
    // if(nr < 0 || nr > N || nc < 0 || nc >= M) return false;
    return (map[nr][nc] != 1);
}

void printMap(){
    cout << endl;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M ; j++){
            if(i == R && j == C) {
                switch(D){
                    case 0:
                        cout << "^ ";
                        break;
                    case 1:
                        cout << "> ";
                        break;
                    case 2:
                        cout << "| ";
                        break;
                    case 3:
                        cout << "< ";
                        break;
                    
                }
            }
            else{
                cout << map[i][j] << " ";
            }
        }
        cout << "\n";
    }
    cout << endl;
    usleep(300 * 1000);
}
int main(){
    int cnt = 0;
    int ans = 0;
    cin >> N >> M >> R >> C >> D;
    map.resize(N);
    
    for(int r = 0; r < N ;r++){
        map[r].resize(M);
        for(int c =  0; c < M ; c++){
            cin >> map[r][c];
        }
    }
    // printMap();
    while(1){
        // action #1
        if(map[R][C] == 0){
            map[R][C] = 2;
            cnt = 0;
            ans += 1;
        }
        for(; cnt < 4 ; cnt++){
            D = turnLeft(D);
            int nr = R + dr[D], nc = C + dc[D];
            if(map[nr][nc] == 0){
                R = nr, C = nc;
                break;
            }
            // printMap();
        }
        if(cnt == 4){
            if(map[R - dr[D]][C - dc[D]] == 1) break;
            else {
                R -= dr[D];
                C -= dc[D];
                cnt = 0;
            }
        }
        // printMap();
        // action #2
    }
    cout << ans;
    return 0;
}