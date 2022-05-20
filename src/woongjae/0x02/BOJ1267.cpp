#include <iostream>

using namespace std;

int main()
{
    int n;
    int i;
    int result1, result2;
    int time;

    i = 0;
    result1 = 0;
    result2 = 0;
    cin >> n;
    while (i < n)
    {
        cin >> time;
        result1 += time / 30 + 1;
        result2 += time / 60 + 1;
        i++;
    }
    result1 = result1 * 10;
    result2 = result2 * 15;

    if (result1 > result2)
        cout << "M " << result2;
    else if (result1 < result2)
        cout << "Y " << result1;
    else if (result1 == result2)
        cout << "Y M " << result1;

    return (0);
}