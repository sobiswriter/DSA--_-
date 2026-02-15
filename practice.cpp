#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n){
    for(int i=0; i<n-i-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//Discovery: How to print the last no in the array using selection Sort. ;)
void SelectionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]>arr[min_idx]){
                min_idx = j;
            }
        }
        if(min_idx!=i){
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        
        }
    }
}

void InsertionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int key = arr[i];
        int j = i-1;
        //it's sorta like backtracking yk 
        while(j>=0 && arr[j]<key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
}



int main(){
    cout<<"how many nums again: \n";
    int n;
    cin>> n;
    int arr[n];
    cout<<"Put an array as big as "<<n<<" nums: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    InsertionSort(arr, n);
    
    cout<<"\nHere is ur array Maam: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}