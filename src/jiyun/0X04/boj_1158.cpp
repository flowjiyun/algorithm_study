#include <bits/stdc++.h>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  int n,k;
  cin >> n >> k; 
  vector <int> V;
  vector <int> ans;

  for (int i = 1; i <= n; i++)
    V.push_back(i);

  for (int i = 0; ans.size() < n; i++)
  { 
    if(i % k == k-1) // 조건 충족시 정답 수열에 해당 값 저장
        ans.push_back(V[i]);
    else 
        V.push_back(V[i]); // 불충족시 뒤로 연결
  }

  cout << "<";
  for(int i = 0; i < n; i++)
  {
    if(i == n-1) 
        cout << ans[i];
    else 
        cout << ans[i] << ", ";
  }
  cout << ">";
}