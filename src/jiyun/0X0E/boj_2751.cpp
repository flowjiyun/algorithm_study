#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000001];
int tmp[1000001];

void merge(int st, int en){
  int mid = (st+en)/2;
  int left = st;
  int right = mid;
  for (int i = st; i < en; i++)
  {
    if (left == mid)
        tmp[i] = arr[right++];
    else if (right == en)
        tmp[i] = arr[left++];
    else if (arr[left] <= arr[right])
        tmp[i] = arr[left++];
    else
        tmp[i] = arr[right++];
  } 
  for (int i = st; i < en; i++)
  {
    arr[i] = tmp[i];
  }
}

void merge_sort(int st, int en){
  if(en == st + 1) return; 
  int mid = (st+en)/2;
  merge_sort(st, mid);
  merge_sort(mid, en);
  merge(st, en);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  merge_sort(0, n);
  for(int i = 0; i < n; i++) cout << arr[i] << '\n';
}