// 2004A Closest Point

#include <iostream>
#include <vector>
using namespace std;

string closestPoint(vector<int>& nums) {
    const int n = nums.size();
    if (n > 2) 
        return "NO";

    int i = nums[0];
    int j = nums[1];
    
    if (abs(i-j) < 2) 
        return "NO";
    
    return "YES";
}

int main() {
    int t ;
    cin>>t;
    vector<int> nums;
    for (int i=0; i<t; ++i) {
        int n ;
        cin>>n;
        nums.resize(n);
        for (int j=0; j<n; ++j) 
            cin>>nums[j];
        cout<<closestPoint(nums)<<endl;
    }
    return 0;
}