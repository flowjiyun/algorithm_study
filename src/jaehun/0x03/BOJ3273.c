//두 수의 합
#include <stdio.h>
# define SWAP(x, y, tmp) ( (tmp)=(x), (x)=(y), (y)=(tmp) )

void quicksort (int *arr, int L, int R) {
    int pivot = arr[L];
    int tmp;
    int left=L, right=R;
    while (left <= right) {
        while (arr[left]<pivot)
            left++;
        while (arr[right]>pivot)
            right--;
        if (left <= right) {
            SWAP(arr[left], arr[right], tmp);
            left++;
            right--;
        }
    }
    if (L < right)
        quicksort(arr, L, right);
    if (left < R)
        quicksort(arr, left, R);
}

int main() {
    int n, target, cnt=0;
    scanf("%d", &n);
    int arr[n];
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &target);
    quicksort(arr, 0, n-1);
    int i=0;
    int j=n-1;
    while (i<j) {
        if (arr[i]+arr[j] < target)
            i++;
        else if(arr[i]+arr[j] > target)
            j--;
        else if (arr[i]+arr[j] == target) {
            cnt++;
            i++;
            j--;
        }
    }
    printf("%d", cnt);
}