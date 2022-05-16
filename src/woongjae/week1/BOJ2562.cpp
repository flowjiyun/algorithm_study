#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int arr[9];
    int i;
    int result;

    i = 0;
    result = 0;
    while (i < 9)
    {
        cin >> arr[i];
        i++;
    }
    i = 0;
    while (i < 8)
    {
        result = max(result , (max(arr[i], arr[i + 1])));
        i++;
    }
    cout << result << "\n";
    i = 0;
    while (i < 9)
    {
        if(result == arr[i])
        {
            cout << i + 1;
            return (0);
        }
        i++;
    }
    return (0);
}