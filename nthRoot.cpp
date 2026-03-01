#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    long long cal(int base, int exp, int limit) {
        long long result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
            if (result > limit) return LLONG_MAX;
        }
        return result;
    }

    int nthRoot(int n, int m) {
        int lo = 0, hi = m;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            long long power = cal(mid, n, m);

            if (power == m) return mid;
            else if (power < m) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Solution obj;
    cout << obj.nthRoot(n, m) << endl;

    return 0;
}