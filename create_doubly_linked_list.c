#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    struct node* next1;
    int data;
    struct node* next2;
}node;

node* create_new_node(int data){
    node* new_node = malloc(sizeof(node));
    new_node->next1= NULL;
    new_node->data =data;
    new_node->next2=NULL;
    return new_node;
}
node* append_node_to_doubly_linked_list(node* head,int data){
   
    if(head == NULL){
        head = create_new_node(data);
    }

    else{
        node* temp = head;
        while(temp->next2!=NULL){
            temp = temp->next2;
        }
        temp->next2=create_new_node(data);
    }
   return head;
}

void print_doubly_linked_list(node* head){
    node* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next2;
    }
    printf("NULL\n");
}
int main(){
    
    node* head=NULL;
    head =append_node_to_doubly_linked_list(head,10);
    print_doubly_linked_list(head);
}