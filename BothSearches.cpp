#include <iostream>
using namespace std;

//Both searches Baby ;)

void InsertionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
//Linear Search
int LinearSearch(int arr[], int n, int t){
    for(int i=0; i<n; i++){
        if(arr[i] == t){
            return i;
        }
        
    }
    return -1;
}
//Binary Search
int BinarySearch(int arr[], int n, int t){
    int high = n-1;
    int low = 0;
    
    while(low <= high){
        int mid = low + (high - low)/2;
        
        if (arr[mid] == t){
            return mid;
        }
        
        if (arr[mid] > t){
            high = mid - 1;
        } else {
            low = mid + 1; 
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    InsertionSort(arr, n);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    int t;
    cin>>t;
    cout<<"\n"<<LinearSearch(arr, n, t);
    cout<<"\n"<<BinarySearch(arr, n, t);
    return 0;
}