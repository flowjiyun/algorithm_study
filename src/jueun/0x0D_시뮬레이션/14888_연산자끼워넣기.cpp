#include <iostream>

using namespace std;

int operators[4];
int arr[11];
int mmin = 1000000001;
int mmax = -1000000001;
int n;

void fun(int result, int cnt)
{
    if (cnt == n)
    {
        if (result > mmax)
            mmax = result;
        if (result < mmin)
            mmin = result;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (operators[i] > 0)
        {

            operators[i]--;

            if (i == 0)
                fun(result + arr[cnt], cnt + 1);
            else if (i == 1)
                fun(result - arr[cnt], cnt + 1);
            else if (i == 2)
                fun(result * arr[cnt], cnt + 1);
            else
                fun(result / arr[cnt], cnt + 1);

            operators[i]++;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> operators[i];
    }

    fun(arr[0], 1);

    cout << mmax << "\n";
    cout << mmin;
    return 0;
}