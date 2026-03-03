#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:

    int possibleDay(int arr[], int n, int capacity){
        int days = 1;
        int load = 0;

        for(int i = 0; i < n; i++){
            if(load + arr[i] > capacity){
                days++;
                load = arr[i];
            } else {
                load += arr[i];
            }
        }

        return days;
    }

    int leastWeightCapacity(int arr[], int n, int d) {

        int s = INT_MIN;
        int e = 0;

        // Define search space
        for(int i = 0; i < n; i++){
            s = max(s, arr[i]);  // minimum capacity
            e += arr[i];         // maximum capacity
        }

        // Binary Search on Answer
        while(s <= e){
            int mid = s + (e - s) / 2;

            if(possibleDay(arr, n, mid) <= d){
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return s;
    }
};

int main() {
    Solution sol;

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 5;

    cout << "Least Weight Capacity: "
         << sol.leastWeightCapacity(arr, n, d)
         << endl;

    return 0;
}