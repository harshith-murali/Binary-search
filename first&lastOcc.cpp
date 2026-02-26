#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        if (lb == arr.size() || arr[lb] != x) {
            return {-1, -1};
        }

        int ub = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

        return {lb, ub - 1};
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 2, 2, 2, 3, 4};
    int x = 2;

    vector<int> result = sol.find(arr, x);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}