/*
    state : -------- -------- -------- --------
    12 1.5 3 4.5  6 7.5 9 10.5
    7  6   5 4    3  2  1  0
*/

#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;
unsigned char state[5];

void printBit(unsigned char bits){
    int n = 7;
    while(n >= 0){
        cout << (int)((bits & (1 << n)) >> n);
        n--;
    }
}

unsigned char& saveBit(unsigned char & bits, int n){
    bits ^= (1 << n);
    return bits;
}
unsigned char& eraseBit(unsigned char & bits, int n){
    bits &= (~(1 << n));
    return bits;
}

int getBit(const unsigned char & bits, int n){
    return ((bits & (1 << n)) >> n);
}

void print(){
    for(int i = 1 ; i <= 4; i++){
        printBit(state[i]);
        cout << " ";
    }
    cout << endl << endl;
}

void turnCounterClockwise(int idx, int from);
void turnClockwise(int idx, int from){
    bool turnLeft = false, turnRight = false;
    
    if(from >= idx && idx >= 2){
        turnLeft = (getBit(state[idx - 1], 5) != getBit(state[idx], 1)); 
    }
    if(from <= idx && idx <= 3){
        turnRight = (getBit(state[idx], 5) != getBit(state[idx + 1], 1));
    }

    if(getBit(state[idx] , 0) == 1){
        state[idx] >>= 1;
        saveBit(state[idx], 7);
    }else {
        state[idx] >>= 1;
        eraseBit(state[idx], 7);
    }
    // cout << "turn Clock " << idx << "\n";
    // print();
    // cout << "will call turnLeft : " << turnLeft << " and turnRight : " << turnRight << "\n"; 
    if(turnLeft) turnCounterClockwise(idx - 1, idx);
    if(turnRight) turnCounterClockwise(idx + 1, idx);
    return ;
}

void turnCounterClockwise(int idx, int from){
    bool turnLeft = false, turnRight = false;
    
    if(from >= idx && idx >= 2){
        turnLeft = (getBit(state[idx - 1], 5) != getBit(state[idx], 1)); 
    }
    if(from <= idx && idx <= 3){
        turnRight = (getBit(state[idx], 5) != getBit(state[idx + 1], 1));
    }
    if(getBit(state[idx] , 7) == 1){
        state[idx] <<= 1;
        saveBit(state[idx], 0);
    }else { 
        state[idx] <<= 1;
        eraseBit(state[idx], 0);
    }
    // cout << "turn Counter " << idx << "\n";
    // print();
    // cout << "will call turnLeft : " << turnLeft << " and turnRight : " << turnRight << "\n"; 
    if(turnLeft) turnClockwise(idx - 1, idx);
    if(turnRight) turnClockwise(idx + 1, idx);
    return;
}

int main(){
    for(int t = 1 ; t <= 4 ;t++){
        string ipt;
        int n = 7;
        cin >> ipt;
        for(auto & ch : ipt){
            if(ch == '1'){
                state[t] = state[t] ^ (1 << n);
            }
            n--;
        }
    }
    int K;
    cin >> K;
    for(int i = 0 ; i < K ; i++){
        int clockwise, num;
        cin >> num >> clockwise;
        if(clockwise == 1){
            turnClockwise(num, num);
        }else{
            turnCounterClockwise(num, num);
        }
    }
    int score = 1, ans = 0;
    for(int i = 1; i <= 4; i++){
        ans += getBit(state[i], 7) * score;
        score *= 2;
    }
    cout << ans;
    return 0;
}