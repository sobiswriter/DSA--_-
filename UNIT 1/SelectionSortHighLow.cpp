#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n){
    // first version (buggy for practice)
    for(int i=0; i<n-1; i++){
        int min_idx = i;
        for(int j=0; j<n-1; j++){
            if(j<min_idx){
                arr[j]=arr[min_idx];
            }
        }
        
        if(min_idx != i){
            int temp = arr[min_idx];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
        
    }
}

void SelectionSort(int arr[], int n){
    // second version (also buggy)
    for(int i=0; i<n; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(j>min_idx){
                arr[min_idx] = arr[j];
            }
        
        if(min_idx != i){
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
        }
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
    
    SelectionSort(arr, n);
    
    cout<<"Here is ur arr maam: \n";
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
        
        
    }
    return 0;
}