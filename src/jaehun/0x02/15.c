#include <stdio.h>
//카드 역배치
int *swap(int a, int b)
{

}

int main()
{
    int arr[21] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int i, j, l, tmp;
    for (i=0; i<10; i++)
    {
        scanf("%d %d", &j, &l);
        while (j < l)
        {
            tmp = arr[j];
            arr[j] = arr[l];
            arr[l] = tmp;
            j++;
            l--;
        }
    }
    for (int n = 1; n<21; n++)
        printf("%d ", arr[n]);
}