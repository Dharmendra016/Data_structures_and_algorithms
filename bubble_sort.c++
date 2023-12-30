//bubble sorting 
#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

int main(){
    
    vector<int> arr = {1 , 5 , 0 , 3 , 8 , 2} ; 

    int size = arr.size() ; 

    //before sorting
    cout<<"Before sorting"<<endl;
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;

    //sorting
    for(int i = 0 ; i<size-1 ; i++){

        for(int j = 1; j<(size-i) ; j++){
            int firstEle = arr[j-1] ;
            int secondEle = arr[j] ;

           if(firstEle > secondEle){
                swap(arr[j] , arr[j-1]);
           }
        }
    }
    
    //after sorting
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;

    

    return 0;
}