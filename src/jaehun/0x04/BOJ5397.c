//키로거
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *next;
    struct node *prev;
} node;

int main() {
    int n;
    scanf("%d ", &n);
    for (int i=0; i<n; i++) {
        node* head = (node*)malloc(sizeof(node));
        head->data = '#';
        head->next = NULL;
        head->prev = NULL;
        node* cur = head;
        char c;
        while ((c=getchar()) != '\n') {
            node* word = (node*)malloc(sizeof(node));
            word->data = c;
            word->next = NULL;
            word->prev = cur;
            cur->next = word;
            if (cur->data == '-') {
                if (cur->prev == NULL) {
                    continue;
                }
                else if (cur->prev->prev == NULL) {
                    if (cur->next != NULL) {
                        cur->prev->next = cur->next;
                        cur->next->prev = cur->prev;
                        printf("1");//
                    }
                    else if (cur->next == NULL) {
                        cur->prev->next = NULL;
                        cur = cur->prev;
                        printf("2");//
                    }
                }
                else if (cur->prev->prev != NULL) {
                    if (cur->next != NULL) {
                        cur->prev->prev->next = cur->next;
                        cur->next->prev = cur->prev->prev;
                        printf("3");//
                    }
                    else if (cur->next == NULL) {
                        cur->prev->prev->next = NULL;
                        printf("4");//
                    }
                }
                else
                    return 0;
            }
            else if (cur->data == '<') {
                cur->prev->next = cur->next;
                if (cur->next != NULL)
                    cur->next->prev = cur->prev;
                if (cur->prev != NULL) {
                    cur = cur->prev;
                }
            }
            else if (cur->data == '>') {
                if (cur->next != NULL)
                    cur->next->prev = cur->prev;
                cur->prev->next = cur->next;
            }
            if (cur->next != NULL)
                cur = cur->next;
        }
    head = head->next;
    while (head) {
        printf("%c", head->data);
        head = head->next;    }
    }
}