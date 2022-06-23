//나이순 정렬
#include <stdio.h>
#include <string.h>

int n;
int old[100000];
int tmpold[100000];
char name[100000][101];
char tmpname[100000][101];

void merge(int st, int en) {
    int mid = (st+en)/2;
    int l = st;
    int r = mid;
    for (int i=st; i<en; i++) {
        if (r == en) {
            tmpold[i] = old[l];
            for (int j=0; j<strlen(name[l]); j++) {
                tmpname[i][j] = name[l][j];
                tmpname[i][j+1] = 0;
            }
            l++;
        }
        else if (l == mid) {
            tmpold[i] = old[r];
            for (int j=0; j<strlen(name[r]); j++) {
                tmpname[i][j] = name[r][j];
                tmpname[i][j+1] = 0;
            }
            r++;
        }
        else if (old[l] <= old[r]) {
            tmpold[i] = old[l];
            for (int j=0; j<strlen(name[l]); j++) {
                tmpname[i][j] = name[l][j];
                tmpname[i][j+1] = 0;
            }
            l++;
        }
        else if (old[l] > old[r]) {
            tmpold[i] = old[r];
            for (int j=0; j<strlen(name[r]); j++) {
                tmpname[i][j] = name[r][j];
                tmpname[i][j+1] = 0;
            }
            r++;
        }
    }
    for (int i=st; i<en; i++) {
        old[i] = tmpold[i];
        for (int j=0; j<strlen(tmpname[i]); j++) {
            name[i][j] = tmpname[i][j];
            name[i][j+1] = 0;
        }
    }
}

void merge_sort(int st, int en) {
    if (st == en-1) return;
    int mid = (st+en)/2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf(" %d %s", &old[i], &name[i]);
    merge_sort(0, n);
    for (int i=0; i<n; i++) printf("%d %s\n", old[i], name[i]);
}