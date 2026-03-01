// Use binary search on answer space when:

// The answer is a value (number, time, distance, capacity, etc.), not necessarily an index.

// The input is unsorted or irrelevant to searching directly.

// You can define a check(mid) function that answers a yes/no question.

// The result of check(mid) is monotonic (once true → always true, or vice versa).

// Based on check(mid), half of the search space can be discarded.

// If you can convert a problem into a monotonic yes/no check over a range, binary search applies — even if nothing is sorted.

#include <iostream>
using namespace std;

class Solution
{
public:
    int floorSqrt(int n)
    {
        if (n == 0 || n == 1)
            return n;

        int ans = 1;
        int s = 1, e = n;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (mid <= n / mid)
            { // overflow-safe
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution obj;
    cout << obj.floorSqrt(n) << endl;

    return 0;
}