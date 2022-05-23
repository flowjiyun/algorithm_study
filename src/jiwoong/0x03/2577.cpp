#include <iostream>
using namespace std;

int num[10];
int main(){
    int A, B, C;
    cin >> A >> B >> C;
    long long res = A * B * C;
    while(res != 0){
        num [res % 10]++;
        res /= 10;
    }
    for(auto ele : num){
        cout << ele << "\n";
    }
    return 0;
}