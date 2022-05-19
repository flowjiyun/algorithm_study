//애너그램 만들기
#include <stdio.h>
#include <string.h>
int main() {
    char str1[1001];
    char str2[1001];
    int arr1[26]= {};
    int arr2[26]= {};
    int cnt = 0;
    scanf("%s", str1);
    scanf("%s", str2);
    for (int i=0; i<strlen(str1); i++)
        arr1[str1[i]-'a']+=1;
    for (int i=0; i<strlen(str2); i++)
        arr2[str2[i]-'a']+=1;
    for (int i=0; i<26; i++) {
        if (arr1[i] - arr2[i] > 0)
            cnt += (arr1[i] - arr2[i]);
        if (arr1[i] - arr2[i] < 0)
            cnt -= arr1[i] - arr2[i];
    }
    printf("%d", cnt);
}