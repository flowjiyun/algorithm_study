#include <iostream>
#include <stdio.h>


using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i, j;
    int a;
    int result[3];
    int tmp;

    tmp = 0;
    i = 0;
    a = 0;
    while(i < 3)
    {
        j = 0;
        while (j < 4)
        {
            cin >> a;
            tmp += a;
            a = 0;
            j++;
        }
        result[i] = tmp;
        tmp = 0;
        i++;
    }
    i = 0;
    while(i < 3)
    {
        if(result[i] == 3)
            cout << "A" << "\n";
        else if(result[i] == 2)
            cout << "B" << "\n";
        else if(result[i] == 1)
            cout << "C" << "\n";
        else if(result[i] == 0)
            cout << "D" << "\n";
        else if(result[i] == 4)
            cout << "E" << "\n";
        i++;
    }
    return (0);
}