#include <iostream>
using namespace std;

int max_val(int a, int b){
    return (a > b) ? a : b;
}
int main(){
    int dices[3];
    for (int i = 0 ; i < 3; i++)
        cin >> dices[i];
    if (dices[0] == dices[1] && dices[1] == dices[2]){
        cout << 10000 + dices[0] * 1000;
    }else if(
    dices[0] != dices[1] && 
    dices[1] != dices[2] &&
    dices[2] != dices[0]){
        cout << max_val(dices[0], max_val(dices[1], dices[2])) * 100;
    }else{
        if (dices[0] == dices[1])
            cout << 1000 + dices[0] * 100;
        else if (dices[1] == dices[2])
            cout << 1000 + dices[1] * 100;
        else if (dices[2] == dices[0])
            cout << 1000 + dices[2] * 100;
    }
    return 0;
}