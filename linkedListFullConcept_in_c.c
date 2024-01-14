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




    return 0;
}