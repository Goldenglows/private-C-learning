#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create_list(int data) {
    struct node *head = (struct node*) malloc(sizeof(struct node));
    head->data = data;
    head->next = NULL;
    return head;
}

void insert_node(struct node *head, int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    struct node *last_node = head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }

    last_node->next = new_node;
}

void delete_node(struct node *head, int data) {
    struct node *prev_node = head;
    struct node *curr_node = head->next;

    while (curr_node != NULL) {
        if (curr_node->data == data) {
            prev_node->next = curr_node->next;
            free(curr_node);
            break;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
}

struct node* find_node(struct node *head, int data) {
    struct node *curr_node = head->next;

    while (curr_node != NULL) {
        if (curr_node->data == data) {
            return curr_node;
        }
        curr_node = curr_node->next;
    }

    return NULL;
}

void print_list(struct node *head) {
    struct node *curr_node = head->next;

    while (curr_node != NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }

    printf("\n");
}

int main() {
    struct node *head = create_list(0);

    insert_node(head, 1);
    insert_node(head, 2);
    insert_node(head, 3);

    print_list(head);

    delete_node(head, 2);

    print_list(head);

    struct node *found_node = find_node(head, 1);
    if (found_node != NULL) {
        printf("Found node with data %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}
