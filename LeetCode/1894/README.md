# 2022 Find the Student that Will Replace the Chalk

You can checkout the problem statemment [here](https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/).

## Thought Process

Originally, we simulate the entire process as it is given. But, due to given constraints this can be very time consuming.

More efficient approach, would be to mod `k` by total chalks consumed in one pass, so we are effectively reducing problem to just one pass. This is achieved using prefix sum, and last element would be the amount of chalks consumed in one pass.

Now we can effectively search in `prefixSum` array to find the index where chalks falls insufficient. We can use binary search to speed up our finding because array is already sorted.

## [🔗Solution File](solution.cpp)

## Code Snippet 
```cpp
// cpp
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // time complexity : O(n)
        // space complexity : O(n)
        const int n = chalk.size();
        vector<long> prefixSum(n);
        prefixSum[0] = chalk[0];
        for (int i=1; i<n; ++i)
            prefixSum[i] = prefixSum[i-1] + chalk[i];

        k %= prefixSum[n-1];

        int l = 0, r = n-1;
        while (l <= r) {
            int mid = l + (r-l)/2;

            if (prefixSum[mid] == k) 
                return (mid+1)%n;
            else if (prefixSum[mid] < k)
                l = mid+1;
            else
                r = mid-1;
        }

        return l%n;

    }
};
```