#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *next;
  //定义下一个节点  
};

struct node * creat_list (int data){
    //创造节点
    struct node *head = (struct node*)malloc (sizeof(struct node));
    head -> data = data;
    head -> next =NULL;
    return head;
}

// void insert_node (struct node *head, int data){
//     struct node *new_Node = (struct node*)malloc(sizeof(struct node) );
//     //插入新节点
//     new_Node->data = data;
//     new_Node->next = NULL;

//     struct node *last_node = head;
 
// }

