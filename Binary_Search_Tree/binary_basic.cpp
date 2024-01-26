#include<iostream>
using namespace std; 

class Node {
    public:
        int data ; 
        Node* left ; 
        Node* right ; 

        Node(int d){
            data = d ; 
            left = NULL ; 
            right = NULL ; 
        }
    
};

Node* insertNode(Node* root , int d){

    if( root == NULL ){
       Node* newNode = new Node(d);
        return newNode ; 
    }

    if( d > root->data){
        root->right = insertNode(root->right , d);
    }else {
        root->left = insertNode(root->left , d);
    }
    return root ; 
}

void preOrder(Node* root){
    if( root == NULL){
        return ; 
    }

    cout<<root->data <<endl; 

    preOrder(root->left) ; 
    
    preOrder(root->right);
   
}

void inOrder(Node* root){
    if( root == NULL){
        return ; 
    }

    inOrder(root->left) ; 
    cout<<root->data <<endl; 
    inOrder(root->right);
}

void postOrder(Node* root){
    if( root == NULL){
        return ; 
    }

    inOrder(root->left) ; 
    inOrder(root->right);
    cout<<root->data <<endl; 
}


void searchingNode(Node* root , int dat){

    if( dat == root->data){
        cout<<"founded"<<endl;
        return;
    }else{
        cout<<"Not founded"<<endl;
        return;
    }

    if( dat > root->data){
        searchingNode(root->right , dat) ; 
    }else if(dat < root->data){
        searchingNode(root->left , dat);
    }
}


int main(){

    Node* root = NULL ; 
    root = insertNode(root , 10);
    insertNode(root , 20);
    insertNode(root , 8);
    insertNode(root , 15);
    cout<<"pre Order"<<endl;
    preOrder(root);
    cout<<"in Order"<<endl;
    inOrder(root);
    cout<<"post order"<<endl;
    postOrder(root);

    cout<<"Searching node 20 "<<endl;
    searchingNode(root , 20);

    
    cout<<"Searching node 02 "<<endl;
    searchingNode(root , 02);
    return 0 ; 
}