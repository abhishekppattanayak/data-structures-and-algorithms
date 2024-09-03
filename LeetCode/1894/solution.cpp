// LeetCode 1894 Finding Student that will Replace the chalk

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