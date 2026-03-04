#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int f(vector<int>& arr, int sum) {
        int cnt = 1;
        long long curr = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (curr + arr[i] <= sum) {
                curr += arr[i];
            } else {
                cnt++;
                curr = arr[i];
            }
        }
        return cnt;
    }

    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();

        int s = *max_element(arr.begin(), arr.end());
        int e = accumulate(arr.begin(), arr.end(), 0);

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (f(arr, mid) > k) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return s;
    }
};

int main() {
    vector<int> arr = {7, 2, 5, 10, 8};
    int k = 2;

    Solution obj;
    cout << obj.splitArray(arr, k) << endl;

    return 0;
}