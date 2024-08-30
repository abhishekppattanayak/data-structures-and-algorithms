// 2004C Splitting Items

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

int main () {
    int t;
    cin>>t;
    
    vector<int> nums;
    for (int i=0; i<t; ++i) {
        int n, k;
        cin>>n;
        cin>>k;
        
        nums.resize(n, 0);
        for (int j=0; j<n; ++j)
            cin>>nums[j];
        
        cout<<splittingItems(n, nums, k)<<endl;
    }
    
    return 0;
}