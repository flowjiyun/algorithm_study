#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    vector<int> ans;
    int n;
    int cnt;
    int flag = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> n;
        v.push_back(n);
    }

    for (int i = 0; i < 9; i++)
    {
        if (flag)
            break;
        for (int j = i + 1; j < 9; j++)
        {
            if (flag)
                break;
            cnt = 0;
            for (int k = 0; k < 9; k++)
            {
                if (k != i && k != j)
                    cnt += v[k];
            }

            if (cnt == 100)
            {
                for (int k = 0; k < 9; k++)
                {
                    if (k != i && k != j)
                        ans.push_back(v[k]);
                }
                flag = 1;
            }
        }
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < 7; i++)
        cout << ans[i] << "\n";

    return 0;
}