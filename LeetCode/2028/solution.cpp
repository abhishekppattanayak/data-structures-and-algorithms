// LeetCode 2028 Find Missing Observations

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, const int n) {
        // time complexity : O(n)
        // space complexity : O(n)
        
        const int m = rolls.size();
        int totalSum = mean*(n+m);
        int sumOfMObservations = accumulate(rolls.begin(), rolls.end(), 0);
        int targetSum = totalSum - sumOfMObservations;

        if (targetSum > n*6 || targetSum < n)
            return {};
        
        vector<int> ans(n, 6);
        int i = 0;
        int currentSum = n*6;
        int diff = currentSum-targetSum;
        
        while (diff > 0) {
            if (diff < 6) {
                ans[i] -= diff;
                diff = 0;
            }
            else {
                ans[i] -= 5;
                diff -= 5;
                ++i;
            }
        }

        return ans;
    }
};