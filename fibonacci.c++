#include<iostream>
using namespace std; 

int fibo(int n ){

    if(n == 0 || n == 1){
        return n ;
    }

    return fibo(n-1) + fibo(n-2) ; 

}

int f[10] ;
int fiboMemozation(int n){
    
    if(n == 0 || n == 1){
        f[n] = n ;
        return n ;
    }else{
        if(f[n-2] == -1){
            f[n-2] = fibo(n-2);
        }
        if( f[n-1] = -1){
            f[n-1] = fibo(n-1);
        }
    }

    return f[n-1] + f[n-2] ; 

}
int main(){

    int n ; 
    cin>>n ; 

    int ntermFibo = fibo(n) ; 
    cout<<ntermFibo; 

    return 0;
}