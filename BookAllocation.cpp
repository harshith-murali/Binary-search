#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int countStudents(vector<int> &arr, int pages) {
        int students = 1;
        long long pagesStudent = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (pagesStudent + arr[i] <= pages) {
                pagesStudent += arr[i];
            } else {
                students++;
                pagesStudent = arr[i];
            }
        }
        return students;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1;

        int s = *max_element(arr.begin(), arr.end());
        int e = accumulate(arr.begin(), arr.end(), 0);

        while (s <= e) {
            int mid = s + (e - s) / 2;

            int students = countStudents(arr, mid);

            if (students > k) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return s;
    }
};

int main() {
    int n, k;

    cout << "Enter number of books: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter pages of each book:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of students: ";
    cin >> k;

    Solution obj;
    int result = obj.findPages(arr, k);

    cout << "Minimum maximum pages allocated: " << result << endl;

    return 0;
}