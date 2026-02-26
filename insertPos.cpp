#include<iostream>
#include<vector>
using namespace std;

int main(){
    // insert position is the first element which is greater than the key
    int n , key;
    cin>>n>>key;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int low = 0 , high = n-1 , mid;
    while(low <= high){
        mid = low + (high-low)/2;
        if(arr[mid] > key){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
        
}
cout<<"Insert position is at index "<<low;
}
