#include <stdio.h>
#include <string.h>

void scanf_with_space() {
    char al[10];
    printf("input with space: ");
    scanf("%s[^\n]", al);
    printf("al is %s\n", al);
}

int main(void) {
    char a[10];
    printf("input: ");
    scanf("%s", a);

    printf("a is %s\n", a);
    return (0);
}