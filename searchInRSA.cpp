#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int key) {
        int s = 0, e = arr.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == key) return mid;

            // Left half sorted
            if (arr[s] <= arr[mid]) {
                if (arr[s] <= key && key < arr[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            // Right half sorted
            else {
                if (arr[mid] < key && key <= arr[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int key = 0;

    int index = sol.search(arr, key);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}