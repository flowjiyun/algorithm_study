#include <iostream>
using namespace std;
int arr[100000];
int t;

int main()
{
    int k, num;
    cin >> k;

    for (int i = 0; i < k; i++){
        cin >> num;

        if (num == 0) t--;
        else {
            arr[t] = num;
            t++;
        }
    }

    int sum = 0;
    while (--t >= 0) sum += arr[t];
    cout << sum;
}
