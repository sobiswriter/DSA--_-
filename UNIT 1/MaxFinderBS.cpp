#include <iostream>
using namespace std;

void BubbleSortR(int arr[], int n){
    // descending bubble sort to find max
    for(int i=0; i<n-1; i++){
        // passes
        for(int j=0; j<n-1-i; j++){
            // compare adjacent
            if(arr[j]<arr[j+1]){
                // swap if smaller first
                int temp = arr[j+1];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
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
    
    cout<<"Max is: ";
    cout<<arr[0];  // first element is max after descending sort
    return 0;
}