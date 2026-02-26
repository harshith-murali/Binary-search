#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n , key;
    cin>>n>>key;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int low = 0 , high = n-1 , mid;
    while(low <= high){
        mid = low + (high-low)/2;
        if(arr[mid] == key){
            cout<<"Element found at index "<<mid;
            return 0;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout<<"Element not found in the array";
    return 0;
}