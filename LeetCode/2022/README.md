# 2022 Convert 1D Array Into 2D Array

You can checkout the problem statemment [here](https://leetcode.com/problems/convert-1d-array-into-2d-array/).

## Thought Process

We will iterate though the `original` array and simultaneously, adding `rows` to the `ans` array. This is a straightforward solution without much of thinking required.

## [🔗Solution File](solution.cpp)

## Code Snippet 
```cpp
// cpp
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
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
```