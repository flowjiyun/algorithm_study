//배열 합치기

#include <stdio.h>

int main() {
    int A[1000000];
    int B[1000000];
    int C[2000000];
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++)
        scanf(" %d", &A[i]);
    for (int i=0; i<m; i++)
        scanf(" %d", &B[i]);
    int aidx=0, bidx=0;
    for (int i=0; i<n+m; i++) {
        if (bidx == m) C[i] = A[aidx++];
        else if (aidx == n) C[i] = B[bidx++];
        else if (A[aidx] <= B[bidx]) C[i] = A[aidx++];
        else if (A[aidx] > B[bidx]) C[i] = B[bidx++];
    }
    for (int i=0; i<n+m; i++)
        printf("%d ", C[i]);
}