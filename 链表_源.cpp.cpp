#include <stdio.h>
#include <stdlib.h>

//定义链表节点
typedef struct Node {
    int data;
    struct Node* next;
}Node;

//创建链表
Node* createList(int n) {
    int i;
    Node* head, * p, * q;
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    q = head;
    for (i = 0; i < n; i++) {
        p = (Node*)malloc(sizeof(Node));
        scanf("%d", &p->data);
        p->next = NULL;
        q->next = p;
        q = p;
    }
    return head;
}

//插入节点
void insertNode(Node* head, int x) {
    Node* p, * q;
    p = head;
    while (p->next != NULL) {
        q = p->next;
        if (q->data >= x) {
            break;
        }
        p = p->next;
    }
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = x;
    node->next = p->next;
    p->next = node;
}

//删除节点
void deleteNode(Node* head, int x) {
    Node* p, * q;
    p = head;
    while (p->next != NULL) {
        q = p->next;
        if (q->data == x) {
            p->next = q->next;
            free(q);
            break;
        }
        p = p->next;
    }
}

//遍历链表
void printList(Node* head) {
    Node* p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//查找节点
int searchNode(Node* head, int x) {
    Node* p = head->next;
    int pos = 0;
    while (p != NULL) {
        pos++;
        if (p->data == x) {
            return pos;
        }
        p = p->next;
    }
    return -1;
}

int main() {
    int n, x, y, pos;
    Node* head, * p;
    printf("请输入链表长度：");
    scanf("%d", &n);
    head = createList(n);
    printf("链表：");
    printList(head);
    printf("请输入要插入的节点：");
    scanf("%d", &x);
    insertNode(head, x);
    printf("插入后的链表：");
    printList(head);
    printf("请输入要删除的节点：");
    scanf("%d", &y);
    deleteNode(head, y);
    printf("删除后的链表：");
    printList(head);
    printf("请输入要查找的节点：");
    scanf("%d", &x);
    pos = searchNode(head, x);
    if (pos == -1) {
        printf("节点不存在！\n");
    }
    else {
        printf("节点在第%d个位置\n", pos);
    }
    return 0;
}
