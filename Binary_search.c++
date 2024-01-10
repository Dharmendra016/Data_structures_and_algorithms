#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std; 

int main(){

    vector<int> arr = {1 , 5 , 2 , 6 , 0} ; 
    sort(arr.begin() , arr.end());
    int n = arr.size() ; 

    int s = 0 ; 
    int e = n-1; 

    int mid = s + (e-s)/2 ;

    int ele = 5; 
    while( s<=e){

        if( ele == arr[mid]){
            cout<<"ele founded:"<<ele<<endl;
            break;
        }
        else if(ele > arr[mid]){
            s = mid +1 ;
        }else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }

    return 0;
}