#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakElement(vector<int> &arr) {
        int n = arr.size();

        if (n == 1) return 0;

        if (arr[0] > arr[1]) return 0;
        if (arr[n - 1] > arr[n - 2]) return n - 1;

        int s = 1, e = n - 2;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid] > arr[mid - 1]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    int peakIndex = obj.peakElement(arr);

    cout << peakIndex << endl;
    return 0;
}