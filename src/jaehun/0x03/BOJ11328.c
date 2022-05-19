//Strfry
#include <stdio.h>
#include <string.h>
int main() {
    int N;
    char str1[1001], str2[1001];
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%s %s", &str1, &str2);
        int arr1[26] = {}, arr2[26] = {};
        for (int i=0; i<strlen(str1); i++)
            arr1[str1[i]-'a']+=1;
        for (int i=0; i<strlen(str2); i++)
            arr2[str2[i]-'a']+=1;
        for (int i=0; i<26; i++) {
            if (arr1[i] != arr2[i]) {
                printf("Impossible\n");
                break ;
            }
            if (i==25)
                printf("Possible\n");
        }
    }
}