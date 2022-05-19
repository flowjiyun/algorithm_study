#include <iostream>

using namespace std;
int a[10];

int GetLength(int result)
{
    int length = 0;
    if (result == 0)
        return (1);
    while (result != 0)
    {
        result /= 10;
        length++;
    }
    return length;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int nb; 
    int length;
    int result = 1;
    for (int i = 0; i < 3; i++)
    {
        cin >> nb;
        result *= nb;
    }
    length = GetLength(result);
    for (int i = 0; i < length; i++)
    {
        a[result % 10]++;
        result /= 10;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << '\n';
    }
    return (0);
}