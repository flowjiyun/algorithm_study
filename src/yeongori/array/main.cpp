#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int N){
    int n[101] = {};
    for (int i = 0; i < N; i++){
        if (n[100 - arr[i]])
            return (1);
        n[arr[i]] = 1;
    }
    return (0);
}

int main(void)
{
    // vector<int> v1(3, 5); // {5, 5, 5}
    // cout << v1.size() << "\n"; // 3
    // v1.push_back(7); // {5, 5, 5, 7}

    // vector<int> v2(2); // {0, 0}
    // v2.insert(v2.begin() + 1, 3); // {0,3,0}

    // vector<int> v3 = {1,2,3,4}; //{1,2,3,4}
    // v3.erase(v3.begin() + 2); // {1,2,4}

    // vector<int> v4;
    // v4 = v3;
    // cout << v4[0] << v4[1] << v4[2] << '\n';
    // v4.pop_back(); // {1, 2}
    // v4.clear(); // {}

    // vector<int> v5 = {1,2,3,4,5,6};

    // for (int e : v5)
    //     cout << e << ' ';
    
    // for (int i = 0; i < v5.size(); i++)
    //     cout << v5[i] << ' ';

    // for (int i = 0; i <= v5.size() - 1; i++)
        // cout << v5[i] << ' ';
    
    int arr[4] = {4,13,63,87};
    for (int i: arr)
    {

    }
    cout << func2(arr, 4);
    return (0);
}