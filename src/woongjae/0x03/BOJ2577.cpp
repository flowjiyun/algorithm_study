#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    int result;
    int num;
    int j;
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int cnt[10] = {0};
    cin >> a >> b >> c;
    result = 0;
    num = 0;

    result = a * b * c;
    while (result > 0)
    {
        num = result % 10;
        j = 0;
        while (j < 10)
        {
            if(arr[j] == num)
                cnt[j]++;
            j++;
        }
        result = result / 10;
        num = 0;
    }
    j = 0;
    while (j < 10)
    {
        cout << cnt[j] << "\n";
        j++;
    }
}