#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n) {
    // selection sort, takes array and size
    for (int i = 0; i < n - 1; i++){
        // outer loop for each position
        int min_idx = i;
        // assume current i is min index
        for(int j = i+1; j < n; j++){
            // inner loop from i+1 to end
            if (arr[j] < arr[min_idx]){
                // if arr[j] smaller, update min_idx
                min_idx=j;
            }
        }
        // swap min with current i if different
        if(min_idx!=i){
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

//same old output loop
int main(){
    cout<<"Enter length of arr: ";
    int n;
    cin>> n;
    
    cout<<"Enter "<<n<<" length array: ";
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    SelectionSort(arr, n);
    
    cout<<"Here is your sorted array: \n";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}