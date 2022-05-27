#include <iostream>
#include <stack>
#include <utility>

#include <cstdlib>
#include <ctime>
using namespace std;

#define VAL first
#define IDX second

#define START 0
#define END 1000000000
template<typename T>
T maxVal(T a, T b) { return (a > b) ? a : b; }

long long h[100002];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // srand((unsigned int)time(NULL));
    int N = 1;
    cin >> N;
    while(N != 0){
        stack<pair<long long, int>> s;
        s.push(make_pair(-1, 0));
        long long ans = 0;
        for (int i = 1 ; i <= N ; i++)
        {
            // h[i] = rand() % (END - START + 1) + START;
            // cout << h[i] << " ";
            cin >> h[i];
        }
        h[N + 1] = 0;
        // cout << endl;

        for (int i = 1 ; i <= N + 1 ; i++){
            if(s.top().VAL < h[i]){
                ans = maxVal(ans, h[i]);
                s.push(make_pair(h[i], i));
            }else{
                pair<long long, int> popped;
                // cout << "Testing in stack\n";
                while(!s.empty() && s.top().VAL >= h[i]){
                    ans = maxVal(ans, s.top().VAL * (i - s.top().IDX));
                    // cout << s.top().VAL << " * " << (i - s.top().IDX) << " = " << ans << endl;
                    popped = s.top();
                    s.pop();
                }
                //assert s.top().VAL < h[i]
                // cout << "Testing h[i] with stack\n";
                ans = maxVal(ans, h[i] * (i - s.top().IDX));
                // cout << h[i] << " * " << (i - s.top().IDX) << " = " << ans << endl;
                
                if (popped.VAL == h[i])
                {
                    ans = maxVal(ans, popped.VAL * (i - s.top().IDX));
                    // cout << popped.VAL << " * " << (i - s.top().IDX) << " = " << ans << endl;
                    s.push(popped);
                }
                s.push(make_pair(h[i], i));
            }
        }
        cout << ans << "\n";
        cin >> N;
    }
    return 0;
}