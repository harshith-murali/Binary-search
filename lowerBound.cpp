#include<iostream>
#include<vector>
using namespace std;

int main(){
    // lower bound is the first element which is greater than or equal to the key
    int n , key;
    cin>>n>>key;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int low = 0 , high = n-1 , mid;
    while(low <= high){
        mid = low + (high-low)/2;
        if(arr[mid] >= key){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout<<"Lower bound is at index "<<low;
}