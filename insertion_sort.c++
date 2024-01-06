//bubble sorting 
#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

int main(){
    
    vector<int> arr = {1 , 2,2,3,5 , 0 , 3 , 8 , 2} ; 

    int size = arr.size() ; 

    //before sorting
    cout<<"Before sorting"<<endl;
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;

    //sorting
    for(int i = 1 ; i<size ; i++){
        int j = i-1;
        int temp = arr[i] ; 

        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j] ; 
            j--;
        }

        arr[j+1] = temp;
    }
    
    //after sorting
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;

    

    return 0;
}