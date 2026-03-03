#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums, int divisor, int threshold) {
        long long sum = 0;

        for (int x : nums) {
            sum += (x + divisor - 1) / divisor;  // correct ceil
            if (sum > threshold) return false;   // early exit
        }

        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1;
        int e = *max_element(nums.begin(), nums.end());

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (isPossible(nums, mid, threshold))
                e = mid - 1;
            else
                s = mid + 1;
        }

        return s;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    cout << "Smallest Divisor: " 
         << sol.smallestDivisor(nums, threshold) 
         << endl;

    return 0;
}