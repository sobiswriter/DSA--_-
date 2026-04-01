#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n){
    for(int i = 0; i<n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

//can't believe did it one go!!
void selectionSort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        int min_idx = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }
        if(min_idx!=i){
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

void oldLS(int arr[], int n, int t){
    for(int i = 0; i<n; i++){
        if(arr[i] == t){
            cout<<"\nfound -_-\n";
        }
    }
}

void linearSearch(const vector<int>& arr, int t){
    for(int n: arr){
        if(n == t){
            cout<<"Found!\n";
        }
    }
}

void printArray(const vector<int>& arr){
    for(int i: arr){
        cout<<i;
    }
}

void BS(int arr[], int n, int t){
    int high = n-1;
    int low = 0;
    while(low<=high){
        int mid = low + (high - low)/2;
        
        if(arr[mid]==t){
            cout<<"Found mid: "<<arr[mid]<<"\n";
        }
        
        if(arr[mid]>t){
            high = mid -1;
        } else {
            low = mid +1;
        }
        
    }
}

int main(){
    int n = 5;
    int arr[n] = {2, 3, 1, 5, 4};
    vector<int> num = {2, 3, 1, 5, 4};
    //bubbleSort(arr, n);
    //insertionSort(arr, n);
    selectionSort(arr, n);
    cout<<"Array: ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
    int t = 4;
    oldLS(arr, n, t);
    BS(arr, n, t);
    
    linearSearch(num, t);
    printArray(num);
    
    return 0;
}