#include <iostream>
using namespace std;

int arr[10];
int main(){
    int N;
    cin >> N;
    while(N!=0){
        arr[N % 10]++;
        N /= 10;
    }
    int max = 0;
    for (int i = 0 ; i < 10; i++){
        if (i == 6 || i == 9)
            max = (max < ((arr[6] + arr[9] + 1) / 2)) ? ((arr[6] + arr[9] + 1) / 2) : max;
        else
            max = (max < arr[i])?arr[i]:max;
    }
    cout << max;
    return 0;
}