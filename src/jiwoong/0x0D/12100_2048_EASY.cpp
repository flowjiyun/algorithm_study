#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unistd.h>
using namespace std;
int N;
int ans = 0;
int dr[4] = {+1, 0, -1, 0};
int dc[4] = {0, +1, 0, -1};
int ir[4]; // 0 0 N - 1 N - 1 = > N - 1 N -1 0 0
int ic[4];
// (400 +  )* 4 ^5

bool isInside(int nr, int nc){
    if(nr < 0 || nr >= N || nc < 0 || nr >= N) return false;
    return true;
}

void move(int n, vector<vector<int>>& map){
    if(n >= 5){
        int M = 0; 
        for(auto & vec : map){
            for(auto & ele : vec){
                M = max(M, ele);
            }
        }
        ans = max(ans, M);
        return;
    }


    for(int d = 0; d < 4; d++){
        // cout << "Move : ";
        // switch(d){
        //     case 0:
        //         cout << "down \n";
        //         break;
        //     case 1:
        //         cout << "right \n";
        //         break;
        //     case 2:
        //         cout << "up \n";
        //         break;
        //     case 3:
        //         cout << "left \n";
        //         break;
        // }
        // move up & down
        stack<int> s;
        vector<vector<int>> temp(map);
        for(int x = 0 ; x < N ; x++){
            //for each x 
            int r, c;
            for(int step = 0 ; step < N; step++){
                r = x*(dr[d] == 0) + ir[d] + step * dr[d], c = x*(dc[d] == 0) + ic[d] + step * dc[d];
                // cout << "( " << r << " , " << c << ")\n";
                if(temp[r][c] == 0) continue;
                s.push(temp[r][c]);
                // if(step < N - 1){
                //     int nxt = step + 1;
                //     int nr = r + dr[d], nc = c + dc[d];
                //     while(nxt < N && temp[nr][nc] == 0){
                //         nr += dr[d], nc += dc[d];
                //         nxt += 1;
                //     }
                //     if(nxt < N){ // temp[nr][nc] != 0
                //         if(temp[nr][nc] == temp[r][c]){
                //             s.push(2*temp[r][c]);
                //             step = nxt;
                //         }else{
                //             s.push(temp[r][c]);
                //             step = nxt - 1;
                //         }
                //     }else {
                //         s.push(temp[r][c]);
                //         break;
                //     }
                // }
                // else s.push(temp[r][c]);
            }
            for(int step = N - 1; step >= 0 ; step--){
                r = x*(dr[d] == 0) + ir[d] + step * dr[d], c = x*(dc[d] == 0) + ic[d] + step * dc[d];
                if(s.empty()) temp[r][c] = 0;
                else{
                    temp[r][c] = s.top();
                    s.pop();
                    if(!s.empty() && s.top() == temp[r][c]) {
                        s.pop();
                        temp[r][c] *= 2;
                    }
                }
            }
        }
        
        // for(auto & vec : temp){
        //     for(auto & ele : vec){
        //         cout << ele << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // usleep(300 * 1000);
        // system("cls");
        move(n + 1, temp);
    }
}

int main(){
    vector<vector<int>> map;
    cin >> N;
    map.resize(N);
    for(auto & vec : map){
        vec.resize(N);
        for(auto & ele : vec) cin >> ele;
    }
    // ir 0   +0 N - 1 0
    ir[0] = ir[1] = ir[3] = 0;
    // ic +0  0 +0     N - 1
    ic[0] = ic[1] = ic[2] = 0;
    ir[2] = ic[3] = N - 1;
    move(0, map);
    cout << ans;
    return 0;
}