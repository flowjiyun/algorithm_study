//방 배정
#include <stdio.h>
int main() {
    int N, K, S, Y, room=0;
    scanf("%d %d", &N, &K);
    int student[N];
    int cnt[12] = {};
    for (int i=0; i<N; i++){
        scanf("%d %d", &S, &Y);
        student[i] = 6*S + Y -1;
    }
    for (int i =0; i<N; i++)
        cnt[student[i]]++;
    for (int i=0; i<12; i++) {
        room += cnt[i]/K;
        if (cnt[i]%K)
            room++;
    }
    printf("%d", room);
}