#include <iostream>
#include <climits>
using namespace std;

int main(){
    int num[7];
    int sum = 0;
    int min_val = 101;
    for (int i = 0 ;i < 7; i++){
        cin >> num[i];
        if (num[i] % 2 == 1){
            sum += num[i];
            min_val = (num[i] < min_val)?num[i]:min_val;
        }
    }
    if (sum == 0)
        cout << "-1\n";
    else
    {
        cout << sum <<"\n";
        cout << min_val << "\n";
    }
    return 0;
}