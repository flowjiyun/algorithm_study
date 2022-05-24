#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i;
    int a[5];
    int result;
    int j;
    int tmp;

    tmp = 0;
    i = 0;
    result = 0;
    while (i < 5)
    {
        cin >> a[i];
        result += a[i];
        i++;
    }
    i = 0;
    while (i < 4)
    {
        j = i + 1;
        while (j < 5)
        {
            if (a[i] > a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            j++;
        }
        i++;
    }
    cout << result / 5 << "\n" << a[2];
}