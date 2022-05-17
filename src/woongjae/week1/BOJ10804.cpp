#include <iostream>
#include <string.h>

using namespace std;



int main()
{
    int a[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int m, n;
    int i, j;
    int tmp;

    i = 0;
    tmp = 0;
    while (i < 10)
    {
        cin >> m >> n;
        m--;
        n--;
        j = 0;
        while (j < (n - m + 1) / 2)
        {
            tmp = a[m + j];
            a[m + j] = a[n - j];
            a[n - j] = tmp;
            tmp = 0;
            j++;
        }
        i++;
    }
    i = 0;
    while(i < 20)
    {
        cout << a[i] << " ";
        i++;
    }
    return (0);
}