#include<iostream>

using namespace std; 

class Node{
    public: 
        int data ; 
        Node* left ; 
        Node*right ; 

        Node(int data ){
            this->data = data ; 
            left = NULL ; 
            right = NULL ; 
        }
};

void insertNode(Node* &root , int d){

    if( root == NULL ){
        return ; 
    }

    if( d > root->data){
        insertNode(root->right , d) ; 
    }else if( d < root->data ){
        insertNode(root->left , d);
    }

}

int main(){

    Node* root = new Node(10);
    insertNode(root , 5) ; 
    insertNode(root , 6);


    return 0 ; 
}
