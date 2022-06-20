/*
    위 : 북쪽 row --
    오 : 동쪽 col ++
    아 : 남쪽 row ++
    왼 : 서쪽 col --

    //좌표 : (x, y) 의 수는 항상 0

    //dice : 윗 1 / 동 3 => 아래 6 / 서 4 / 북 5 남 2 (각각의 면 인덱스)

    남쪽으로 이동 : 2가 바닥행 (남쪽 보는 애가 바닥으로감)
    //처음에는 주사위에 모든 면에 0, 
    //칸 0 => 주사위에서 바닥으로 옮기기
    //칸 N => 바닥에서 주사위로 옮기기

*/
#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<vector<int>> map;
/*
    u s e w n d
    1 2 3 4 5 6
    0 0 0 0 0 0 

    map[nr][nc] == 0 => map[nr][nc] = dice[move]
    map[nr][nc] != 0 => dice[move] = map[nr][nc];

    이러고 dice state 업데이트
    move north :
    d -> s -> u -> n -> d
    move south :
    d -> n -> u -> s -> d
    move east  :
    d -> w -> u -> e -> d
    move wast  :
    d -> e -> u -> w -> d
*/

vector<int> dice(7, 0);
int dr[5] = {0, 0, 0, -1, +1};
int dc[5] = {0, +1, -1, 0, 0};

void updateState(int side){
    int temp = dice[6];
    dice[6] = dice[side];
    dice[side] = dice[1];
    dice[1] = dice[7 - side];
    dice[7 - side] = temp;
}

void printDice(){
    cout <<"u s e w n d\n";
    for(int i = 1; i <= 6; i++){
        cout << dice[i] << " ";
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int x, y, K;
    cin >> x >> y>> K;
    map.resize(N);
    for(int r = 0 ; r < N ; r++){
        map[r].resize(M);
        for(int c = 0 ; c < M; c++){
            cin >> map[r][c];
        }
    }
    for(int k = 0 ; k < K ; k++){
        int cmd, nr, nc, side;
        cin >> cmd;
        nr = x + dr[cmd], nc = y + dc[cmd];
        // cout << "( " << nr << " , "<< nc << ")\n";
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        switch(cmd){
            case 1: // 동
                side = 3;
                break;
            case 2: // 서
                side = 4;
                break;
            case 3: // 북
                side = 5;
                break;
            case 4: // 남
                side = 2;
                break;
            default:
                break;
        }
        updateState(side);
        if(map[nr][nc] != 0) {
            dice[6] = map[nr][nc];
            map[nr][nc] = 0;
        }
        else map[nr][nc] = dice[6];
        x = nr, y = nc;
        // switch(cmd){
        //     case 1:
        //         cout << "move east :\n";
        //         break;
        //     case 2:
        //         cout << "move west :\n";
        //         break;
        //     case 3:
        //         cout << "move north :\n";
        //         break;
        //     case 4:
        //         cout << "move south :\n";
        //         break;
        // }
        // printDice();
        cout << dice[1] << "\n";
    }
    return 0;
}