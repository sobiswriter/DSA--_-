#include <iostream>
using namespace std;

//Discovery: Same as bofore, exchaning the >,< makes it assending and decending 
//And using break get highest and lowerst stuff as well ;) enjoy ur Vtine now with some good food! >_<
void InsertionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int key = arr[i];
        int j = i - 1;
        //then using a while loop we see if let's say index j is >= 0 & value of j is greater than key
        while(j>=0 && arr[j] < key){
            //we're shifting shit at right (j+1) to left (j)
            arr[j+1] = arr[j];
            //we're going one score back as well
            j=j-1;
        }
        //now that made some free space right, fill that using this below
        arr[j+1] = key;
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
    
    InsertionSort(arr, n);
    
    cout<<"Here is ur arr maam: \n";
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
        
        
    }
    return 0;
}