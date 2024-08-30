# 2004A Closest Point

You can checkout the problem statemment [here](https://codeforces.com/problemset/problem/2004/C).

## Thought Process

Alice and Bob both are playing optimally. So, both of them would like to take the largest number present. So, this is a greedy-type of problem.

We sort the array in non-increasing order. Since, Alice goes first she will take the items in `even` indices and Bob will takes items in `odd` indices (Remeber array indexing starts from `0`).

Now, Bob will try to minimize the score by making sure `odd` elements are as close to previous `even` elements. So, he will set them as `min(k, even-odd)`. Simultaneously, checking if he doesn't surpass the threshold limit.

## [🔗Solution File](solution.cpp)

## Code Snippet 
```cpp
int splittingItems (int n, vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());
    for (int i=0, j=1; j<n && k>0; i+=2, j+=2) {
        int diff = nums[i] - nums[j];
        int x = min(k, diff);
        k -= x;
        nums[j] += x;
    }
    int score = 0;
    for (int i=0; i<n; ++i) 
        if (i%2)
            score -= nums[i];
        else
            score += nums[i];
    return score;
}
```