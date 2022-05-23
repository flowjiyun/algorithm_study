#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
};

void traverse(struct Node *head)
{
    struct Node *cur;
    cur = head->next; //head node(dummy node)의 다음을 가리킴
    while(cur != 0)
    {
        cout << cur->data << ' ';
        cur = cur->next;
    }
}

void insert(struct Node *addr, int data)
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = addr->next;
    addr->next = newnode;
    newnode->pre = addr;
    addr->next->pre = addr;
}

void DeleteNode(struct Node *addr)
{
    addr->next->pre = addr->pre;
    addr->pre->next = addr->next;
    free(addr);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);


}