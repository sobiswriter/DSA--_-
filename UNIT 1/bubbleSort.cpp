#include <iostream> 
using namespace std;

void bubbleSort(int arr[], int n) {
    // bubble sort, takes array and size
    for (int i = 0; i < n - 1; i++) {
        // outer loop for each pass
        for (int j = 0; j < n - i - 1; j++) {
            // inner loop to compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // swap if out of order
                int temp = arr[j];
                arr[j] =arr[j + 1];
                arr[j + 1] = temp;
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
    
    // loop to get input
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    bubbleSort(arr, n); // calling our function
    
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}