#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n){
    // insertion sort, takes array and size
    for(int i=0; i<n; i++){
        // loop through each element
        int key = arr[i];
        // key is current element to insert
        int j = i - 1;
        // j starts from previous element
        while(j>=0 && arr[j] < key){
            // while j valid and arr[j] < key (for descending sort)
            arr[j+1] = arr[j];
            // shift arr[j] to right
            j=j-1;
            // move j left
        }
        arr[j+1] = key;
        // place key in correct position
    }
}

int main(){
    cout<<"how many nums agn: ";
    int n;
    cin>> n;
    int arr[n];
    cout<<"put "<<n<<" count arr: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    InsertionSort(arr, n);
    
    cout<<"Here is ur arr maam: \n";
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
        
        
    }
    return 0;
}