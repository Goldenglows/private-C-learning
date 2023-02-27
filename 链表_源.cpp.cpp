#include <stdio.h>
#include <stdlib.h>

//��������ڵ�
typedef struct Node {
    int data;
    struct Node* next;
}Node;

//��������
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

//����ڵ�
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

//ɾ���ڵ�
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

//��������
void printList(Node* head) {
    Node* p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//���ҽڵ�
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
    printf("�����������ȣ�");
    scanf("%d", &n);
    head = createList(n);
    printf("����");
    printList(head);
    printf("������Ҫ����Ľڵ㣺");
    scanf("%d", &x);
    insertNode(head, x);
    printf("����������");
    printList(head);
    printf("������Ҫɾ���Ľڵ㣺");
    scanf("%d", &y);
    deleteNode(head, y);
    printf("ɾ���������");
    printList(head);
    printf("������Ҫ���ҵĽڵ㣺");
    scanf("%d", &x);
    pos = searchNode(head, x);
    if (pos == -1) {
        printf("�ڵ㲻���ڣ�\n");
    }
    else {
        printf("�ڵ��ڵ�%d��λ��\n", pos);
    }
    return 0;
}
