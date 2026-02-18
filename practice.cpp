#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n){
    for(int i = 0; i<n; i++){
        int min_idx = i;
        //You better not forget to check +1 bitch
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }
        
        if(i != min_idx){
            int temp = arr[i];
            arr[i] =  arr[min_idx];
            arr[min_idx] =  temp;
        }
    }
}

int BinarySearch(int arr[], int n,int t){
    int high = n-1;
    int low = 0;
    
    while(low <= high){
        int mid = low + (high -low)/2;
        
        if(arr[mid] == t){
            return mid;
        } else if (arr[mid] > t){
            high = mid -1;
        } else {
            low = mid +1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    
    int arr[n];
    
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    SelectionSort(arr, n);
    
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    int t;
    cin>>t;
    cout<<BinarySearch(arr, n, t);
    //Sorry Gs, I have had enough for the day....
    return 0;
}