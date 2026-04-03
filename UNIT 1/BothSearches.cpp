#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n){
    // insertion sort, takes array and size
    for(int i=0; i<n; i++){
        // loop through each element
        int key = arr[i];
        // key is current element
        int j = i-1;
        // j starts from previous
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            // shift right
            j=j-1;
            // move left
        }
        arr[j+1]=key;
        // place key
    }
}

// Linear Search
int LinearSearch(int arr[], int n, int t){
    // linear search, takes array, size, target
    for(int i=0; i<n; i++){
        // loop through array
        if(arr[i] == t){
            // if found, return index
            return i;
        }
    }
    return -1;  // not found
}

// Binary Search
int BinarySearch(int arr[], int n, int t){
    // binary search, assumes sorted array
    int high = n-1;
    // high pointer
    int low = 0;
    // low pointer
    while(low <= high){
        // while low <= high
        int mid = low + (high - low)/2;
        // calculate mid
        if (arr[mid] == t){
            // if mid is target, return mid
            return mid;
        }
        if (arr[mid] > t){
            // if arr[mid] > target, search left
            high = mid - 1;
        } else {
            // else search right
            low = mid + 1; 
        }
    }
    return -1;  // not found
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