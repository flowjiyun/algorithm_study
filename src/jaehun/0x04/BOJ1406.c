//에디터
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *next;
    struct node *prev;
    char data;
} node;

int main() {
    node* head = (node*)malloc(sizeof(node));
    head->data = 'X';
    head->next = NULL;
    head->prev = NULL;
    node* cur = head;
    char c;
    while ((c=getchar()) != '\n') {
        node* word = (node*)malloc(sizeof(node));
        word->data = c;
        word->prev = cur;
        word->next = NULL;
        cur->next = word;
        cur = word;
    }
    int M;
    scanf("%d", &M);
    for (int i=0; i<M; i++) {
        char C;
        scanf(" %c", &C);
        if (C == 'L') {
            if (cur->prev != NULL)
                cur = cur->prev;
        }
        else if (C == 'D') {
            if (cur->next != NULL)    
                cur = cur->next;
        }
        else if (C == 'B' && cur->prev != NULL) {
            cur->prev->next = cur->next;
            if (cur->next != NULL)
                cur->next->prev = cur->prev;
            cur = cur->prev;
        }
        else if (C == 'P') {
            char a;
            scanf(" %c", &a);
            node* word = (node*)malloc(sizeof(node));
            word->data = a;
            word->prev = cur;
            if (cur->next != NULL) {
                word->next = cur->next;
                cur->next->prev = word;
            }
            else
                word->next = NULL;
            cur->next = word;
            cur = cur->next;
        }
    }
    head = head->next;
    while (head) {
        printf("%c", head->data);
        head = head->next;
    }
}