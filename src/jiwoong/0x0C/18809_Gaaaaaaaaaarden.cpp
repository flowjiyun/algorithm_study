#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unistd.h>
using namespace std;
#define Pos pair<int, int>
#define row first
#define col second

int N, M, G, R;
int dr[] = {0, +1, 0, -1};
int dc[] = {+1, 0, -1, 0};
vector<bool> isSelected; // 나중에 뽑는 집합의 selectable을 만들기 위해 필요함
vector<Pos> putable;
vector<vector<int>> board;
// selectable은 뽑을 수 있는 원소들의 인덱스를 가지고 있음
// comb크기 만큼 selectable에서 size개 뽑기
bool nextCombination(vector<int>& idx, int size, vector<int>& selectable){
    bool success = false;
    for(int i = size - 1 ; i >= 0 && !success; i--){
        isSelected[idx[i]] = false; // 반납
        // nxt is in [idx[i] + 1, limit)
        int nxt = idx[i] + 1, limit = selectable.size() + i - size + 1;
        for(int s = 0 ; s < limit; s++){
            if(nxt <= selectable[s]){
                success = true;
                idx[i] = selectable[s++];
                isSelected[idx[i]] = true;
                for(int j = i + 1; j < size; j++){
                    idx[j] = selectable[s++];
                    isSelected[idx[j]] = true;
                }
                break;
            }
        }
    }
    return success;
}

void printVis(vector<vector<pair<int, char>>> &vis, int t = 0){
    for(auto & vec : vis){
        for(auto & node : vec){
            if(node.second == 'F') {
                cout << "* ";
                continue;
            }
            if(node.first == -1){
                cout << ". ";
            }else if(node.first == 0){
                cout << node.second << " ";
            }else{
                cout << node.first << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    usleep(t* 1000);
}

int main(){
    int ans = 0;
    cin >> N >> M >> G >> R;
    board.resize(N);
    // board , putable 완성
    for(int i = 0 ; i < N ; i++){
        board[i].resize(M);
        for(int j = 0 ; j < M ; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2){
                putable.push_back(make_pair(i, j));
            }
        }
    }
    isSelected.assign(putable.size(), false);
    // init greenSelectable with 0, 1, 2, 3 ... ,putable.size() - 1
    vector<int> greenSelectable;
    for(int g = 0 ; g < putable.size() ; g++) greenSelectable.push_back(g); 
    // init greenIdx with 0, 1, 2 ... g - 1
    vector<int> greenIdx(G);
    vector<int> redIdx(R);
    for(int g = 0 ; g < G ; g++){
        greenIdx[g] = g;
        isSelected[g] = true;
    }
    // int cnt = 0;
    do{
        
        int r = 0;
        vector<int> redSelectable;
        for(int i = 0 ; i < isSelected.size(); i++){
            if(!isSelected[i]){
                if(r < R){
                    redIdx[r++] = i;
                    isSelected[i] = true;
                }
                redSelectable.push_back(i);
            }
        }
        do{
            int temp = 0;
            // for(auto & ele : greenIdx) cout << ele << " ";
            // cout << "\n";
            // for(auto & ele : redIdx) cout << ele << " ";
            // cout << "\n\n\n";
            // cnt+=1;
            
            vector<vector<pair<int,char>>> visited;
            visited.resize(N);
            queue<pair<Pos, char>> q;
            for(auto & vec : visited) vec.assign(M, make_pair(-1, '\0'));
            for(auto & gre : greenIdx){
                q.push(make_pair(putable[gre], 'G'));
                visited[putable[gre].row][putable[gre].col].first = 0;
                visited[putable[gre].row][putable[gre].col].second = 'G';
            }
            for(auto & red : redIdx){
                q.push(make_pair(putable[red], 'R'));
                visited[putable[red].row][putable[red].col].first = 0;
                visited[putable[red].row][putable[red].col].second = 'R';
            }
            while(!q.empty()){
                Pos pos;
                char ch;
                int r, c;
                tie(pos, ch) = q.front();
                tie(r, c) = pos;
                q.pop();
                if(visited[r][c].second == 'F') continue;
                for(int d = 0 ; d < 4; d++){
                    int nr = r + dr[d], nc = c + dc[d];
                    if(nr < 0 || nc < 0 || nr >= N || nc >= M || 
                    visited[nr][nc].second == 'F' || board[nr][nc] == 0) continue;
                    if(visited[nr][nc].first == -1){
                        visited[nr][nc].first = visited[r][c].first + 1;
                        visited[nr][nc].second = ch;
                        q.push(make_pair(Pos(nr, nc), ch));
                    }else{
                        if(ch == 'R'&& visited[nr][nc].second == 'G' &&
                        visited[nr][nc].first == visited[r][c].first + 1){
                            visited[nr][nc].second = 'F';
                            temp += 1;
                        }
                    }
                }
                // printVis(visited, 500);
            }
            ans = max(ans, temp);
        }while(nextCombination(redIdx, R, redSelectable));
        for(auto & red : redIdx){
            isSelected[red] = false;
        }
    }while(nextCombination(greenIdx, G, greenSelectable));
    // cout << cnt;
    cout << ans;
    return 0;
}