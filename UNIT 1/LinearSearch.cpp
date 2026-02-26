#include <iostream>
using namespace std;

int LinearSearch(int arr[], int n, int t){
    for(int i = 0; i<n; i++){
        
        if(arr[i] == t){
            return i;
        }
    }
    return -1;
}

int main() {
    int n, t;
    
    // 1. Get the size
    cout << "Enter size: ";
    cin >> n;
    
    int arr[n];
    
    // 2. Fill the array
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // 3. Get the target
    cout << "Search for? ";
    cin >> t;
    
    int result = LinearSearch(arr, n, t);
    
    if(result != -1)
        cout << "Found at index: " << result;
    else
        cout << "Not found :(";
        
    return 0;
}