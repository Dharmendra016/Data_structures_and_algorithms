#include<stdio.h>
#include<malloc.h>

struct Node{

    int val ; 
    struct Node* next ; 

};

void insertAtFirst(struct Node** head  , int data){

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->val = data ; 

    if( *head == NULL ){
        printf("The linkelist is empty\n");
        temp->next = NULL ;
        *head = temp; 
        return ;
    }
    temp->next = *head;
    *head = temp ;
    printf("Successfully inserted %d at first " , data);
}

void printAll(struct Node* head){
    struct Node* temp = head ; 
    printf("\nPrinting All node value\n");
    while( temp != NULL ){
        printf("%d\n" , temp->val);
        temp = temp->next ; 
    }

}

void deleteLastNode(struct Node** head){
    struct Node* prev = NULL ; 
    struct Node* curr = *head ; 

    while( curr->next != NULL ){
        prev = curr ; 
        curr = curr->next  ; 
    }

    prev->next = NULL ; 
    free(curr);

}

void searchNode(struct Node** head  , int data){

    struct Node* temp = *head ; 
    int cnt = 1 ;

    while(temp != NULL){
        if( temp->val == data){
            printf("Founded node at position %d" , cnt );
        }
        temp= temp->next ; 
        cnt++;
    }

}

void insertAtLast(struct Node** head  , int data){
    struct Node* curr = *head ;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->val = data ; 

    if( *head == NULL ){
        temp->next = NULL ;
        *head = temp; 
        return ;
    }
    while(curr->next != NULL ){
        curr = curr->next ; 
    }
    temp->next = NULL ; 
    curr->next = temp ; 
}

void insertAtMiddle(struct Node** head  , int position , int data){
    
    if( position == 1 ){
        insertAtFirst(head , data);
        return ;
    }

    int cnt = 1 ; 
    struct Node* temp = *head ;
    while(temp->next != NULL){
        temp = temp->next ; 
        cnt++ ; 
    }

    if(position == cnt){
        insertAtLast(head , data);
        return;
    }
    cnt = 1; 
    temp = *head ; 

    while((cnt+1) != position){
        temp = temp->next ; 
        cnt++ ; 
    }

    struct Node* new = (struct Node*)malloc(sizeof(struct Node)); 
    new->val = data ; 
    
    new->next = temp->next ; 
    temp->next = new ;  

}

int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));   
    head->val = 12 ; 
    head->next = NULL ; 
    insertAtFirst(&head , 22) ; 
    printAll(head);

    deleteLastNode(&head) ; 
    printAll(head);

    insertAtFirst(&head , 45) ;
    insertAtFirst(&head , 20) ;
    insertAtFirst(&head , 5) ;
    printAll(head);
    deleteLastNode(&head) ; 
    printAll(head);
    searchNode(&head , 45);
    insertAtLast(&head , 99);
    printAll(head);
    insertAtMiddle(&head , 3,80);
    printAll(head) ; 
    insertAtMiddle(&head , 1,10);
    printAll(head) ; 

    return 0;
}