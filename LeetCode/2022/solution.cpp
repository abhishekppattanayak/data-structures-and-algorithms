// LeetCode 2022 Construct 1D Array Into 2D Array

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // time complexity : O(mn)
        // space complexity : O(mn)
        vector<vector<int>> ans;
        ans.clear();
        if (m * n != original.size() * 1)
            return ans;
        int i = 0;
        while (i < m * n) {
            int j = 0;
            vector<int> row;
            while (j < n) {
                row.push_back(original[i]);
                i++;
                j++;
            }
            ans.push_back(row);
        }
        return ans;
    }
};