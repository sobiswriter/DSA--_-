#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++){
        //basic loop iteration b&g
        int min_idx = i;
        
        for(int j = i+1; j < n; j++){
            //changing the >,< makes it go assending or discending, easy right!!!
            if (arr[j] < arr[min_idx]){
                min_idx=j;
            }
        
        //The above loop is for exchangeing min index value to get smallest no ig
        //Now we actually make sure smallest no is in right postion
        }
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