#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int i;
    int j;
    int k;
    int l;
    int cnt;
    int arr2[255] = {};
    int arr1[255] = {};
    char **str = new char*[2001];

    cin >> n;
    i = 0;

 //   str = (char **)malloc(sizeof(char *) * ((n * 2) + 1));
//   if (!str)
//       return (0);
    while (i < (n * 2))
    {
        j = 0;
        while (j < 1000)
            cin >> str[i][j++];
        i++;
    }
    str[n] = 0;
    i = 0;
    while (i < n)
    {
        j = i * 2;
        k = 0;
        while (str[j][k])
        {
            if (str[j + 1] && arr2[(unsigned char)str[j + 1][k]] == 0)
                arr2[(unsigned char)str[j + 1][k]] = 1;
            if (str[j + 1] && arr2[(unsigned char)str[j + 1][k]])
                arr2[(unsigned char)str[j + 1][k]]++;
            if (str[j] && arr1[(unsigned char)str[j][k]] == 0)
                arr1[(unsigned char)str[j][k]] = 1;
            if (str[j] && arr1[(unsigned char)str[j][k]])
                arr1[(unsigned char)str[j][k]]++;
            k++;
        }
        l = 0;
        cnt = 0;
        while (l < 255)
        {
            if (arr1[l] == arr2[l])
                cnt++;
            l++;
        }
        if (cnt == 255)
            cout << "Possible" << '\n';
        else
            cout << "Impossible" << '\n';
        arr1[255] = {};
        arr2[255] = {};
        i++;
    }
}
    
