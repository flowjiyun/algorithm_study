#include <iostream>
using namespace std;

int N, r, c;
int po[16][2];

void findNum(int num,int sr, int sc, int level){
    if(level == 0){
        cout << num << "\n";
        return;
    }
    int nxt = num, nr = sr + po[level - 1][0], nc = sc + po[level - 1][0];
    bool rcon = (r >= nr), ccon = (c >= nc);
    nxt += rcon * po[level -1][1] * 2;
    nxt += ccon * po[level -1][1] * 1;
    // cout << sr << " , " << sc << endl;
    findNum(nxt,sr + rcon * po[level - 1][0], sc + ccon * po[level - 1][0], level - 1);
}
int main(){
    po[0][0] = 1;
    po[0][1] = 1;
    for(int i = 1; i <= 15; i++){
        po[i][0] = po[i - 1][0] * 2;
        po[i][1] = po[i - 1][1] * 4;
    }
    cin >> N >> r >> c;
    findNum(0, 0, 0, N);
    return 0;
}