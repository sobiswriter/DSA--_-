#include <iostream>
using namespace std;

void BubbleSortR(int arr[], int n){
    // descending bubble sort
    for(int i=0; i<n-1; i++){
        // passes
        for(int j=0; j<n-i-1; j++){
            // compare adjacent
            if(arr[j]<arr[j+1]){
                // swap if smaller first
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Alt version
void BubbleSortRL(int arr[], int n){
    // another way to write descending sort
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j]<arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
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
    
    BubbleSortR(arr, n);
    
    cout<<"Here is ur arr maam: \n";
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}