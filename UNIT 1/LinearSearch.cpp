#include <iostream>
using namespace std;

void LinearSearch(int arr[], int n, int t){
    // takes 3 parameters: arr (array), n (size), t (target)
    for(int i = 0; i<n; i++){
        // loop through the array
        if(arr[i] == t){
            // check if current element equals target
            cout<<"\nfound -_-\n";
        }
    }
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
    
    LinearSearch(arr, n, t);        
    return 0;
}