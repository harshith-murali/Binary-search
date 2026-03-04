/** Aggressive Cows
Given an array of integers which represents the position of stalls.
We have to place cows in these stalls such that the minimum distance between any two cows is as large as possible.
We are also given the number of cows that we have to place in these stalls.
We have to find the largest minimum distance between any two cows.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canWePlace(vector<int> &stalls, int dist, int k)
    {
        int cntCows = 1;
        int last = stalls[0];

        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - last >= dist)
            {
                cntCows++;
                last = stalls[i];
            }

            if (cntCows >= k)
                return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k)
    {
        sort(stalls.begin(), stalls.end());

        int n = stalls.size();
        int s = 1;
        int e = stalls[n - 1] - stalls[0];

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (canWePlace(stalls, mid, k))
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        return e;
    }
};

int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;

    Solution obj;
    cout << obj.aggressiveCows(stalls, k) << endl;

    return 0;
}