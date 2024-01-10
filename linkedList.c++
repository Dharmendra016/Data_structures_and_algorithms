#include<iostream>
using namespace std; 

//creating a node 
class Node{
    public:
        int val; 
        Node* next ; 

        Node(int d){
            val = d; 
            next = NULL; 
        }
};

void insertAtFirst(Node*& head , int d){
    Node * temp = new Node(d) ; 

    if( head == NULL ){
        head = temp ;   
    }else{
        
        temp->next = head ; 
        head = temp ; 
    }



}

void Dispaly(Node* head){

    while( head != NULL ){
        cout<<head->val<<endl;
        head = head->next ; 
    }

}

void deleteLastNode(Node * &head){

    if(head == NULL){
        cout<<"Empty linkedlist"<<endl;
        return ;
    }else if(head->next == NULL) {
        head = NULL ; 
    }

    Node * curr = head ; 
    Node* pre = NULL ; 


    while (curr->next != NULL) {
        pre = curr;
        curr = curr->next;
    }

    if( pre == NULL ){
        delete head; 
        head = pre ;
        return ;
    }

    pre->next = NULL ; 
    delete curr ; 
}

void searchEle(Node *head , int ele){

    Node* temp = head ; 
    int cnt = 1 ;
    while(temp != NULL ){
        // cout<<temp->val<<endl;
        if( ele == temp->val) {
            cout<<"The element is located at position:"<<cnt<<endl;
            break;
        }
        cnt++;
        temp = temp->next ; 
    }

}

int main(){

    Node *head = NULL; 
    cout<<"insertion"<<endl;
    insertAtFirst(head , 22) ;
    insertAtFirst(head , 21) ;
    insertAtFirst(head , 2) ;
    insertAtFirst(head , 52) ;
    insertAtFirst(head , 82) ;
    Dispaly(head);
    cout<<"deletion"<<endl;
    deleteLastNode(head) ;
    Dispaly(head);
    cout<<"Searching"<<endl;
    searchEle(head , 21);
    searchEle(head , 52);

    return 0;
}