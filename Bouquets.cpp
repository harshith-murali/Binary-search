#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    bool possible(vector<int> &bloomDay, int day, int m, int k)
    {
        int cnt = 0;
        int bouquets = 0;

        for (int x : bloomDay)
        {
            if (x <= day)
            {
                cnt++;
                if (cnt == k)
                {
                    bouquets++;
                    cnt = 0;
                    if (bouquets >= m)
                        return true; // early exit
                }
            }
            else
            {
                cnt = 0;
            }
        }
        return false;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        long long required = 1LL * m * k;
        if (bloomDay.size() < required)
            return -1;

        int s = INT_MAX, e = INT_MIN;

        // single pass to get min and max
        for (int x : bloomDay)
        {
            s = min(s, x);
            e = max(e, x);
        }

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (possible(bloomDay, mid, m, k))
                e = mid - 1;
            else
                s = mid + 1;
        }

        return s;
    }
};

int main()
{
    Solution sol;

    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;

    int result = sol.minDays(bloomDay, m, k);
    cout << "Minimum days: " << result << endl;

    return 0;
}