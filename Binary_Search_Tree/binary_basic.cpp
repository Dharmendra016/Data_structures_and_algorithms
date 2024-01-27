#include<iostream>
using namespace std; 

//class node
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
//insertion
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
//traversing
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

// best case tc = O(logn) || worse case tc = O(n);
void searchingNode(Node* root , int dat){

    if( root == NULL ){
        cout<<"not founded"<<endl;
        return;
    }

    if( dat == root->data){
        cout<<"founded"<<endl;
        return;
    }

    if( dat > root->data){
        searchingNode(root->right , dat) ; 
    }else if(dat < root->data){
        searchingNode(root->left , dat);
    }

    
}

//iterative method ( optimized solution )
bool checkPresentOrNot(Node* root ,  int x){

    while( root != NULL ){
        if( root->data ==  x){
            return true ; 
        }

        if( root->data < x){
            root = root -> right ; 
        }
        else{
            root = root -> left; 
        }

    }
    return false;
}


//min value 
int minValue (Node* root )
{
    if( root->left == NULL ){
        return root->data ; 
    }
    return minValue(root->left);
}

int maxValue(Node * root){
    if( root->right == NULL ){
        return root->data ;
    }

    return maxValue(root->right);
}


Node* deleteFromBst(Node* root , int val){

    if( root == NULL ){
        return root ;
    }

    if( root->data == val){

        if( root->left == NULL && root->right == NULL){
            delete root ; 
            return NULL ; 
        }

        if( root->left != NULL && root->right == NULL ){
            Node* temp = root->left ; 
            delete root ; 
            return temp ; 
        }

        if( root->left == NULL && root->right != NULL ){
            Node* temp = root->right ; 
            delete root ; 
            return temp ; 
        }

        if( root->left != NULL && root->right != NULL ){

            int maxi = maxValue(root->left) ; 
            root->data = maxi  ;
            root->left = deleteFromBst(root->left , maxi ) ; 
            return root ; 
        }

    }

    if( val > root->data){
        root->right = deleteFromBst(root->right , val);
    }else if ( val < root->data){
        root->left = deleteFromBst(root->left , val);
    }
    return root;
}


int main(){

    Node* root = NULL ; 
    root = insertNode(root , 10);
    insertNode(root , 20);
    insertNode(root , 7);
    insertNode(root , 25);
    insertNode(root , 22);
    insertNode(root , 9);
    insertNode(root , 8);
    insertNode(root , 5);
    insertNode(root , 6);
    insertNode(root , 3);


    cout<<"pre Order"<<endl;
    preOrder(root);
    cout<<"in Order"<<endl;
    inOrder(root);
    cout<<"post order"<<endl;
    postOrder(root);

    cout<<"Searching node 20 "<<endl;
    searchingNode(root , 20);

    
    cout<<"Searching node 15 "<<endl;
    searchingNode(root , 15);

    //checking 
    cout<<"checking present or not ";
    cout<<checkPresentOrNot(root , 50)<<endl;
    cout<<checkPresentOrNot(root , 20);
    cout<<endl;
    cout<<"minValue is:";
    cout<<minValue(root)<<endl;
    cout<<"maxValue is:";
    cout<<maxValue(root)<<endl;


    // deletion 
    root = deleteFromBst(root , 7);
    
    inOrder(root);

    return 0 ; 
}