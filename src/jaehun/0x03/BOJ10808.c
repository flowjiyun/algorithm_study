//알파벳 개수
#include <stdio.h>
#include <string.h>
int main() {
    char str[101];
    int arr[26]= {};
    scanf("%s", str);
    for (int i=0; i<strlen(str); i++)
        arr[str[i]-'a']+=1;
    for (int i=0; i<26; i++)
        printf("%d ", arr[i]);
}