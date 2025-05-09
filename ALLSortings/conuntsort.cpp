#include<iostream>
using namespace std ;

void print(int arr[], int n){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " ;
    }
    cout << endl ;
}

int maximum(int arr[] , int n){
    int max = arr[0];
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > max){
            max = arr[i] ;
        }
    }
    return max ;
}

void countsort(int arr[],int n){
    int i , j ;
// find maximum element
int max = maximum(arr,n) ;

// create count array
int *count = new int[max + 1] ;

// intialize count  array element to 0
for(i = 0 ; i < max + 1 ; i++){
    count[i] = 0 ;
}

// Increment the coresponding index in the count array
for(i = 0 ; i < n ; i++){
    count[arr[i]] += 1 ;
}

i = 0 ; // count for count array
j = 0 ; // count for given array

while(i <= max){
    if(count[i] > 0){
        arr[j] = i ;
        j++ ;
        count[i]-- ;
    }else{
        i++ ;
    }
}
}

int main(){
    int arr[] = {3,1,9,7,1,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    print(arr,n);
    countsort(arr,n);
    print(arr,n);
}