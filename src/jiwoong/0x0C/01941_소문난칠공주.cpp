#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unistd.h>
using namespace std;

vector<string> seat(5);
vector<vector<int>> vis(5);

int dr[] = {0, +1, 0, -1};
int dc[] = {+1, 0, -1, 0};
int ida = 0, ans = 0;

void print(vector<int>& vec){
    for(auto & ele : vec){
        cout << ele << " "; 
    }
    cout << endl;
}
bool next_combination(vector<int> &set, int size, int N){
    bool suc = false;
    for(int i = size - 1; i >= 0 ; i--){
        if(set[i] != N + (i - size + 1)){
            set[i] += 1;
            suc = true;
            for(int j = i + 1; j < size; j++){
                set[j] = set[j - 1] + 1;
            }
            break;
        }
    }
    return suc;
}

void dfs(int row, int col){
    for(int d = 0; d < 4; d++){
        int nr = row + dr[d], nc = col + dc[d];
        if(nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
        if(vis[nr][nc] == 1){
            vis[nr][nc] = 2;
            dfs(nr, nc);
        }
    }    
}

void makeRow(int row, int left, int prev){
    if(left == 0){
        bool fin = false, isValid = true;
        for(int r = 0 ; r < 5 && !fin; r++){
            for(int c = 0 ; c < 5 ;c++){
                if(vis[r][c] == 1){
                    vis[r][c] = 2;
                    // cout << r << " " << c << "\n";
                    dfs(r, c);
                    fin = true;
                    break;
                }
            }
        }
        
        for(int r = 0; r < 5 && isValid;r++){
            for(int c = 0 ; c < 5 ;c++){
                if(vis[r][c] == 1) {
                    isValid = false;
                    break;
                }
            }
        }
        if(isValid) {
            //  for(auto & vec: vis){
            //     print(vec);
            // }
            // cout << endl;
            // usleep(300 * 1000);
            ans += (ida >= 4);
        }
        for(int ir= 0 ; ir < 5; ir++){
            for(int ic= 0; ic < 5 ;ic++){
                if(vis[ir][ic] == 2) vis[ir][ic] = 1;
            }
        }
         
        return;
    }
    if(left < 0 || row >= 5){
        return;
    }
    // cout << row << " " << left << "\n";
    for(int l = min(5, left) ; l >= 0; l--){
        if(prev != 0 && l == 0) continue;
        vector<int> temp(l);
        for(int i = 0; i < l ; i++){
            temp[i] = i;
        }
        do{
            for(auto & idx : temp){
                ida += (seat[row][idx] == 'S');
                vis[row][idx] = 1;
            }
            makeRow(row + 1, left - l, l);
            for(auto & idx : temp){
                ida -= (seat[row][idx] == 'S');
                vis[row][idx] = 0;
            }
        }while(next_combination(temp, l, 4));
    }
}



int main(){
    for(auto & vec : vis) vec.assign(5, 0);
    for(auto & str : seat) cin >> str;
    makeRow(0, 7, 0);
    cout << ans;
    return 0;
}