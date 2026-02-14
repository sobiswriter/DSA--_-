#include <iostream>
using namespace std;

//Discovery: Print lowest except the last is the hightest (HighLow)
//This highlow version is volatile though, there are many mistakes that make it different form
//the normal selection sort, but it's still a good practice to understand the logic behind it.
void SelectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min_idx = i;
        //major mistake is j = i+1, because we want to compare the current index with the rest of the array, 
        //not just the next one, so we need to start from i+1 to get the correct min index.
        for(int j=0; j<n-1; j++){
            //also is's kinda interchaed in the if loop as well, do take care of that k! ;)
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