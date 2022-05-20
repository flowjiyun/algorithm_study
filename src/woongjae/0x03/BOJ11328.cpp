#include <iostream>
using namespace std;

int check_str(char *a, char *b)
{
    int i;
    int j;
    int num;
    int alphabet1[26] = {0};
    int alphabet2[26] = {0};

    i = 0;
    while (a[i])
    {
        num = a[i] - 'a';
        alphabet1[num]++;
        i++;
    }
    i = 0;
    while (b[i])
    {
        num = b[i] - 'a';
        alphabet2[num]++;
        i++;
    }
    i = 0;
    while(i < 26)
    {
        j = 0;
        while (j < 26)
        {
            if (alphabet1[i] != alphabet2[i])
            {
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

int main()
{
    int n;
    char a[1000];
    char b[1000];
    int i;

    cin >> n;
    i = 0;

    while (i < n)
    {
        cin >> a >> b;
        if(check_str(a, b))
            cout << "Possible" << "\n";
        else
            cout << "Impossible"<< "\n";
        i++;
    }
    return (0);
}