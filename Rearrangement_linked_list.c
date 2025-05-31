#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//reverse_linked_list
//first,last,second_first,second_last,third_first,third_last....


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


node* resize_linked_list(node* head,int n){
   node* pre = NULL,*next = NULL ,*current = head;
   int count = n;
   node* temp[count/2];
   int j=0;
   int count1=1;
   while((count/2)>=(count1)){
        
    temp[j]=current;
    next=current->next;
    for(int i=1;i<n-1;i++){
        temp[j]=temp[j]->next;
    }
    if((count/2)>count1) {
    current->next=temp[j]->next;
    temp[j]->next = NULL;
    }
   
    if(pre!=NULL){
        pre->next=current;
    }
    pre=current->next;
    current=next;
    n=n-2;
    count1++;
    j++;
 

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
    head=append_node_to_linked_list(head,70);
    head=append_node_to_linked_list(head,80);
    int n = count_and_print_linked_list(head);

    head = resize_linked_list(head,n);
    count_and_print_linked_list(head);

}