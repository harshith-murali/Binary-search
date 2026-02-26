#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int first(vector<int>& arr, int x) {
        int s = 0, e = arr.size() - 1;
        int first = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == x) {
                first = mid;
                e = mid - 1;
            } else if (x > arr[mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return first;
    }

    int last(vector<int>& arr, int x) {
        int s = 0, e = arr.size() - 1;
        int last = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == x) {
                last = mid;
                s = mid + 1;
            } else if (x > arr[mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return last;
    }

    int countFreq(vector<int>& arr, int x) {
        int f = first(arr, x);
        if (f == -1) {
            return 0;
        }
        int l = last(arr, x);
        return l - f + 1;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int x = 2;

    int count = sol.countFreq(arr, x);
    cout << count << endl;

    return 0;
}