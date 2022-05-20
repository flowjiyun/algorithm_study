#include <iostream>
using namespace std;

int main()
{
    int n;
    int k;
    int grade[1000];
    int gender[1000];
    int num[2][7] = {0};
    int i;
    int j;
    int cnt;

    cin >> n;
    cin >> k;
    i = 0;
    cnt = 0;
    while (i < n)
    {
        cin >> gender[i];
        cin >> grade[i];
        i++;
    }
    i = 0;
    while (i < n)
    {
        if (gender[i] == 1)
        {
            switch(grade[i])
            {
                case 1:
                    num[1][1]++;
                    break;
                case 2:
                    num[1][2]++;
                    break;
                case 3:
                    num[1][3]++;
                    break;
                case 4:
                    num[1][4]++;
                    break;
                case 5:
                    num[1][5]++;
                    break;
                case 6:
                    num[1][6]++;
                    break;          
            }
        i++;
        }
        else if (gender[i] == 0)
        {
            switch(grade[i])
            {
                case 1:
                    num[0][1]++;
                    break;
                case 2:
                    num[0][2]++;
                    break;
                case 3:
                    num[0][3]++;
                    break;
                case 4:
                    num[0][4]++;
                    break;
                case 5:
                    num[0][5]++;
                    break;
                case 6:
                    num[0][6]++;
                    break;          
            }
        i++;
        }
    }
    i = 0;
    while (i < 2)
    {
        j = 1;
        while (j <= 6)
        {
            if (num[i][j] != 0 && num[i][j] % k != 0)
                cnt += (num[i][j] / k + 1);
            else if (num[i][j] % k == 0)
                cnt+= num[i][j] / k;
            j++;
        }
        i++;
    }
    cout << cnt;
    return (0);
}