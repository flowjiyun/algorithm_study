#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <unistd.h>

#define MAXSIZE 50
using namespace std;
bool isInside(int r){
    return (0 <= r && r <= MAXSIZE);
}

int main(){
    ofstream ofs(".\\test.txt", ios::out | ios::app);
    if(ofs.fail()){
        cout << "fail\n";
        return -1;
    }
    for(int tn = 0 ; tn <= MAXSIZE; tn++){
        for(int tk = 0 ; tk <= MAXSIZE ;tk++){
            int N = tn , K = tk;
            ofs<< N << " " << K << "\n";
            int step = 0;
            int ans = MAXSIZE + 1;
            // cin >> N >> K;
            cout << N << " " << K << "\n";
            vector<int> timeK(MAXSIZE + 1, -1);
            vector<int> timeC(MAXSIZE + 1, -2);
            queue<int> q;
            while(K + step <= MAXSIZE){
                K += step;
                timeK[K] = step;
                step++;
            }
            q.push(N);
            timeC[N] = 0;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                if (cur == K){
                    if(timeC[cur] == timeK[K]){
                        ans = min(ans, timeK[K]);
                    }else if(timeC[cur] < timeK[K]){
                        // int diff = timeK[K] - timeC[cur];
                        // if(diff % 2 == 0){
                        //     ans = min(ans, timeK[K]);
                        // }
                        // //diff % 2 == 1
                        // else{
                            
                        // }
                    }
                }

                for(int nxt : {2 * cur, cur + 1, cur - 1}){
                    if(isInside(nxt)){
                        if(timeC[nxt] == -1){
                            timeC[nxt] = timeC[cur] + 1;
                            q.push(nxt);
                        }
                    }
                }
            }
            if (ans == MAXSIZE + 1) ofs << "-1\n";
            else ofs << ans << "\n";
            
        }
    }
    return 0;
}