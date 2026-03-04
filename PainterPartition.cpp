#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int countPainter(vector<int>& arr, int time) {
        int painters = 1;
        long long lastTime = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (lastTime + arr[i] <= time) {
                lastTime += arr[i];
            } else {
                painters++;
                lastTime = arr[i];
            }
        }

        return painters;
    }

    int minTime(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n) return -1;

        int s = *max_element(arr.begin(), arr.end());
        int e = accumulate(arr.begin(), arr.end(), 0);

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (countPainter(arr, mid) > k) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return s;
    }
};

int main() {
    vector<int> arr = {5, 10, 30, 20, 15};
    int k = 3;

    Solution obj;
    cout << obj.minTime(arr, k) << endl;

    return 0;
}