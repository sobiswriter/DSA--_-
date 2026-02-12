#include <iostream> 
// we use it to get cin & cout for printing stuff and getting inputs as well.
using namespace std;
// this is so that we don't have to use std::cout everytime.
void bubbleSort(int arr[], int n) {
    // first we make an outer loop using array & int n (where n is actually the size of input)
    for (int i = 0; i < n - 1; i++) {
        
        //yk the for ⬆️ loop, we're determining positions here, for i = 0 for pass
        // for the loop below it's to compare neighbours
        for (int j = 0; j < n - i - 1; j++) {
            
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] =arr[j + 1];
                arr[j + 1] = temp;
                //you'll konw just look at the logic, we're just playing with positions here ;)
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter yr no: ";
    cin >> n; 
    
    int arr[n];
    cout << "Enter array with " << n << " integers: ";
    
    // loop to actaully get the input
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    bubbleSort(arr, n); // calling our funtion
    
    //the loop below is to get the output array, it;s all logic hon
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0; //tells compiler we're done man -_-
    
}