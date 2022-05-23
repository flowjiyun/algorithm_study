#include <iostream>
using namespace std;

int arr[100];

int main(){
    int N, V, ans = 0;
    cin >> N;
    for (int i = 0 ; i < N; i++)
        cin >> arr[i];
    cin >> V;
    for (int i = 0 ; i < N; i++){
        ans += (arr[i] == V);
    }
    cout << ans;
    return 0;
}