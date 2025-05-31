#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
    int data;
    struct node *next;
}node;

node* create_node(int data){
    node* new_node = malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

node* append_node_to_linked_list(node* head,int data){
    if(head == NULL){
        head=create_node(data);
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=create_node(data);
    }
    return head;
}

node* rotate_linked_list(node* head,int count,int k){
    
    node* temp1;
    for(int j=0;j<k;j++){
        node* temp=head;
        for(int i=0;i<count-2;i++){
            temp=temp->next;
        }
        temp1=temp->next;
        temp->next = NULL;
        temp1->next=head;
        head=temp1;
        temp1 =NULL;
    }
    return head;
}
int count_and_print_linked_list(node* head){
    node* temp=head;
    int count=0;
    while(temp!=NULL){
        printf("%d->",temp->data);
        count++;
        temp=temp->next;
    }
    printf("NULL\n");
    return count;
}
int main(){
    node* head = NULL;
    head=append_node_to_linked_list(head,10);
    head=append_node_to_linked_list(head,20);
    head=append_node_to_linked_list(head,30);
    head=append_node_to_linked_list(head,40);
    head=append_node_to_linked_list(head,50);
    head=append_node_to_linked_list(head,60);
    int count = count_and_print_linked_list(head);
    int k=4;
    head = rotate_linked_list(head,count,k);
    count_and_print_linked_list(head);
}