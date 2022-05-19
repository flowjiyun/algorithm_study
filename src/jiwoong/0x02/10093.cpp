#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long A, B;
    cin >> A >> B;
    long long minVal, maxVal;
    if (A > B){
        minVal = B;
        maxVal = A;
    }else if (A < B){
        minVal = A;
        maxVal = B;
    }else{
        cout << "0\n";
        return 0;
    }
    cout << maxVal - minVal - 1 << "\n";
    for (long long i = minVal + 1 ; i < maxVal; i++){
        cout << i << " ";
    }
    return 0;
}