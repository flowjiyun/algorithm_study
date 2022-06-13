#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 시계방향 
// 2^k
// (sx, sy) => (ex, ey)
int po[32];
int goNext(int curState){
    return (curState + 1) % 4;
}

int goPrev(int curState){
    return (4 + curState - 1) % 4;
}

int stay(int curState){
    return curState;
}

// [state][area]
int (*nextState[4][4])(int) ={
    {goNext, stay, stay, goPrev},
    {goPrev, stay, stay, goNext},
    {goNext, stay, stay, goPrev},
    {goPrev, stay, stay, goNext}
};

void makeNextStart(int &nx, int &ny, const int & sx, const int & sy, int area, int level, int reverse){
    switch(area){
        case 0:
            nx = sx;
            ny = sy;
            break;
        case 1:
            nx = sx;
            ny = sy + reverse * po[level - 1];
            break;
        case 2:
            nx = sx + reverse * po[level - 1];
            ny = sy + reverse * po[level - 1];
            break;
        case 3:
            nx = sx + reverse * (po[level] - 1);
            ny = sy + reverse * (po[level - 1] - 1);
            break;
    }
}

/*
    상태 0:
    area 0 : sx, sy
    area 1 : sx, sy + 2^(k - 1)
    area 2 : sx + 2^(k - 1), sy + 2^(k - 1)
    area 3 : sx + 2^k - 1, sy + 2^(k - 1) -1
    상태 1:
    area 0 : sx, sy
    area 1 : sy, sx + 2^(k - 1)
    area 2 : sx + 2^(k - 1), sy + 2^(k - 1)
    area 3 : sy + 2^k - 1, sx + 2^(k - 1) -1
    상태 2:
    area 0 : sx, sy
    area 1 : sx, sy - 2^(k - 1)
    area 2 : sx - 2^(k - 1), sy - 2^(k - 1)
    area 3 : sx - 2^k - 1, sy - 2^(k - 1) -1
    상태 3:
    area 0 : sx, sy
    area 1 : sy, sx + 2^(k - 1)
    area 2 : sy - 2^(k - 1), sx - 2^(k - 1)
    area 3 : sy - 2^k - 1, sx - 2^(k - 1) -1
*/

int level(int N){
    int cnt = 0;
    while(N != 0){
        N /= 2;
        cnt++;
    }
    return cnt - 1;
}

void search(int sx, int sy, int level, int dist, int curState){
    if (dist == 0){
        cout << sx << " " << sy << "\n";
        return;
    }
    int area = dist / po[2*(level - 1)];
    int left = dist % po[2*(level - 1)];
    // cout << sx << " " << sy << " " << dist << "  " << level << " " << curState << " " << area << "\n";
    int nx, ny;
    switch(curState){
        case 0:
            makeNextStart(nx, ny, sx, sy, area, level, 1);
            break;
        case 1:
            makeNextStart(ny, nx, sy, sx, area, level, 1);
            break;
        case 2:
            makeNextStart(nx, ny, sx, sy, area, level, -1);
            break;
        case 3:
            makeNextStart(ny, nx, sy, sx, area, level, -1);
            break;
    }
    search(nx, ny, level - 1, left, nextState[curState][area](curState));
}

int main(){
    po[0] = 1;
    for(int i = 1; i < 32; i++){
        po[i] = po[i - 1] << 1;
    }
    int n, m;
    cin >> n >> m;
    // for(n = 4 ; n <= 8 ; n *= 2){
    //     for(int m = 1; m <= 10 ; m++){
    //         cout << "Testing : " << n << " " << m << "\n";
    //         search(1, 1, level(n), m - 1, 0);
    //     }
    //     cout << "End " << n << " testing\n";
    // }
    search(1, 1, level(n), m - 1, 0);
    return 0;
}