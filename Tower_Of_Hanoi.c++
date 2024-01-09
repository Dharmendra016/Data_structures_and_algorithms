#include<iostream>
using namespace std; 

void TOH(int n , char from , char to , char temp ) {

    if(n == 1){
        printf("move disk 1 from %c to %c \n" , from , to);
        return ;
    }

    TOH(n-1 , from  , temp , to) ; 
    printf("move disk %d from %c to %c \n" ,n ,  from , to);
    TOH(n-1 , temp , to , from ) ; 

}

int main(){

    int n ; 
    cin>>n ; 
    
    TOH(n , 'A' , 'C' , 'B');


    return 0;
}