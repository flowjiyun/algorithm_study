#include <iostream>
using namespace std;

int main()
{
    int n;
    int a[10] = {0};
    int num;

    num = 0;
    cin >> n;
    while (n > 0)
    {
        a[n % 10]++;
        n = n / 10;
    }
    for(int i = 0; i < 10 ; i++)
    {
        if (num < a[i])
        {
            if(i == 6 || i == 9)
            {
                if((a[6] + a[9]) % 2)
                    num = ((a[6] + a[9]) / 2) + 1;
                else
                    num = (a[6] + a[9]) / 2;
            }
            else
                num = a[i];
        }
    }
    cout << num;
    return (0);
}
