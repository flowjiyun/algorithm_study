#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000001];
int tmp[1000001]; // merge 함수에서 리스트 2개를 합친 결과를 임시로 저장하고 있을 변수

// mid = (st+en)/2라고 할 때 arr[st:mid], arr[mid:en]은 이미 정렬이 되어있는 상태일 때 arr[st:mid]와 arr[mid:en]을 합친다.
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

// arr[st:en]을 정렬하고 싶다.
void merge_sort(int st, int en){
  if(en == st + 1) return; // 길이 1인 경우
  int mid = (st+en)/2;
  merge_sort(st, mid); // arr[st:mid]을 정렬한다.
  merge_sort(mid, en); // arr[mid:en]을 정렬한다.
  merge(st, en); // arr[st:mid]와 arr[mid:en]을 합친다.
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  merge_sort(0, n);
  for(int i = 0; i < n; i++) cout << arr[i] << '\n';
}