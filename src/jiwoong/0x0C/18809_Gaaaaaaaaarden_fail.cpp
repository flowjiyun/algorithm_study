#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unistd.h>
using namespace std;

#define Pos pair<int, int>
#define row first
#define col second
int N, M, G, R;
int P = 0, ans = 0;
int dr[] = {0, +1, 0, -1};
int dc[] = {+1, 0, -1, 0};
vector<vector<int>> board;
vector<Pos>     putPos(10); // 0 ... 9번째 자리
vector<bool>    selected(10, false);

vector<int>     redIdx(5);
vector<int>     greenIdx(5);

// 0 ~ P - 1 중 size 개
// selectable : red : 0 1 2 3 4 5 6 7 8 9
//            : green: 0 5 6 7
bool nextCombination(vector<int> & idx, int size, vector<int> &selectable){
    bool suc = false;
    for(int i = size - 1 ; i >= 0 && !suc; i--){
        // 맨마지막 원소부터 한칸 전진시키기 (찾을 때 까지)
        int nxt = idx[i] + 1;
        int s = 0, limit = selectable.size() + i - size + 1;
        selected[idx[i]] = false;
        for(; s < limit; s++){
            if(nxt <= selectable[s]){
                suc = true;
                idx[i] = selectable[s++];
                selected[idx[i]] = true;
                for(int j = i + 1; j < size; j++){
                    idx[j] = selectable[s++];
                    selected[idx[j]] = true;
                }
                break;
            }
        }
    }
    // 만약 끝까지 갔다. 그 전 원소를 전진시키기 반복. -> 그래도 못찾으면 더이상 없는 거.
    // 찾았다면 그 다음 원소부터 마지막 원소까지 1차이나게 최대한 붙여서 넣기.
    return suc;
}

bool isValid(int nr, int nc){
    if(nr < 0 || nr >= N || nc < 0 || nc >= M) return false;
    return true;
}

void print(vector<vector<pair<int,char>>> vis){
    for(auto & vec : vis){
        for(auto & ele : vec){
            if(ele.first == -1) cout << ". ";
            else if(ele.first == -2) cout << "* ";
            else if(ele.first == 0) cout << ele.second << " ";
            else cout << ele.second <<" ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    /*
        1 하얀색 | 배양액 뿌리기 불가
        2 황토색 | 배양액 뿌리기 가능
        0 하늘색 | 호수임
        빨 + 초 동시 도달 = > 꽃 => 더 이상 퍼트리지 않음
    */
    cin >> N >> M >> G >> R;
    board.resize(N);
    for(int i = 0 ; i < N ;i++){
        board[i].resize(M);
        for(int j = 0 ; j < M ; j++){
            cin >> board[i][j];
            if (board[i][j] == 2){
                putPos[P++] = make_pair(i, j);
            }
        }
    }
    putPos.resize(P);
    // for(auto & pos : putPos){
    //     cout << "(" << pos.row <<" , " << pos.col <<")\n";
    // }
    // cout << "\n";
    selected.resize(P);
    redIdx.resize(R);
    greenIdx.resize(G);
    vector<int> selectableR(P);
    for(int i = 0; i < P ; i++) selectableR[i] = i;
    for(int i = 0 ; i < R ; i++){
        redIdx[i] = i;
        selected[i] = true;
    }

    int a = 0;
    do{
        vector<int> selectableG(P - G);
        int g = 0;
        // init selectableG from selectableR
        for(int i = 0 ; i < P; i++){
            if(!selected[selectableR[i]]){
                selectableG[g++] = selectableR[i];
            }
        }
        // init greenIdx from selectableG
        for(int i = 0; i < G; i++){
            greenIdx[i] = selectableG[i];
            selected[selectableG[i]] = true;
        }
        do{
            int cnt = 0;
            Pos pos;
            char ch;
            queue<pair<Pos, char>> q;
            vector<vector<pair<int,char>>> visited;
            visited.resize(N);
            for(auto & vec : visited) vec.assign(M, make_pair(-1, '0'));
            for(auto & red : redIdx){
                q.push(make_pair(putPos[red], 'R'));
                visited[putPos[red].row][putPos[red].col].first = 0;
                visited[putPos[red].row][putPos[red].col].second = 'R';
            }
            for(auto & gre : greenIdx) {
                q.push(make_pair(putPos[gre], 'G'));
                visited[putPos[gre].row][putPos[gre].col].first = 0;
                visited[putPos[gre].row][putPos[gre].col].second = 'G';
            }
            while(!q.empty()){
                tie(pos, ch) = q.front();
                q.pop();
                if(visited[pos.row][pos.col].first == -2) continue;
                if(a == 71){
                    cout << endl;
                    print(visited);
                usleep(500 * 1000);
                }
                for(int d = 0 ; d < 4; d++){
                    int nr = pos.row + dr[d], nc = pos.col + dc[d];
                    if(isValid(nr, nc) && board[nr][nc] != 0 && visited[nr][nc].first != -2){
                        if(visited[nr][nc].first == -1){
                            visited[nr][nc].first = visited[pos.row][pos.col].first + 1;
                            visited[nr][nc].second = ch;
                            q.push(make_pair(Pos(nr, nc), ch));
                        }else{
                            if(visited[nr][nc].second == 'R' && ch == 'G' 
                            && visited[nr][nc].first == visited[pos.row][pos.col].first + 1){
                                cnt += 1;
                                visited[nr][nc].first = -2;
                            } 
                        }
                    }
                }
                // if(cnt == 29) {
                // cout << endl;
                // print(visited);
                // }
            }
            // cout << cnt << endl;
            // usleep(500 * 1000);
            
            ans = max(ans, cnt);
            // if(cnt == 10){
            // cout << a << "\n";
            // cout << "Red :\n";
            // for(auto & red : redIdx){
            //     cout << "(" << putPos[red].row <<" , " << putPos[red].col <<")\n";
            // }
            // cout << "Green:\n";
            // for(auto & gre : greenIdx){
            //     cout << "(" << putPos[gre].row <<" , " << putPos[gre].col <<")\n";
            // }
            // cout << "\n";}
            a++;
        }while(nextCombination(greenIdx, G, selectableG));
        for(auto & gre :greenIdx){
            selected[gre] = false;
        }
    }while(nextCombination(redIdx, R, selectableR));
    cout << ans;
    return 0;
}