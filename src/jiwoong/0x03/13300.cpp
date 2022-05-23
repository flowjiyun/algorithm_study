#include <iostream>
using namespace std;

int rooms[12];

int main(){
    int N , K, ans = 0;
    cin >> N >> K;
    for (int i = 0 ; i < N ; i++){
        int S, G;
        cin >> S >> G;
        rooms[6*S + G - 1]++;
    }
    for(int room : rooms){
        if (room % K == 0)
            ans += room / K;
        else
            ans += room / K + 1;
    }
    cout << ans;
    return 0;
}