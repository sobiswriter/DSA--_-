#include <iostream>
using namespace std;
//Discovery: The Max detector in an array!
void BubbleSortR(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j]<arr[j+1]){
                int temp = arr[j+1];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
//But but but, it's actually easy to get the largest or smallest no, 
//just use a break statement for anti or normal bubble sort, 
//and you'll always get the smallest or largest no in the first iteration, 
//and then you can break the loop to get the max or min no, cool right? 
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
        break;
    }
    return 0;
}