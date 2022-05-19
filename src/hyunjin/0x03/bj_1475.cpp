#include <iostream>
using namespace std;
int dect[9];

int main()
{
    int num;
    cin >> num;

    while (num){
        if (num % 10 == 9) dect[6]++;
        else dect[num % 10]++;

        num /= 10;
    }
    dect[6] = dect[6] / 2 + dect[6] % 2;

    int max = 0;
    for (int i = 0; i < 9; i++){
        if (dect[i] > max) max = dect[i];
    }
    cout << max;
}
