#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] =  arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
//Thoday is a Lucky Day baby ;)
int BinarySearch(int arr[], int n, int t){
    int high = n-1;
    int low = 0;
    while(low <= high){
        int mid = low + (high - low)/2;
        
        if(arr[mid] == t){
            return mid;
        } else if (arr[mid] < t){
            high = mid -1;
        } else {
            low  = mid +1;
        }
    }
    return -1;
}
//No mistakes boys & gs ;)
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    BubbleSort(arr, n);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    int t;
    cin>>t;
    cout<<"\nThe index is: "<<BinarySearch(arr, n, t);
    return 0;
}