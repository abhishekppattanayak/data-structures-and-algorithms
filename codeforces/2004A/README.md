# 2004A Closest Point

You can checkout the problem statemment [here](https://codeforces.com/problemset/problem/2004/A).

## Thought Process

Given a set of points represented on the number line, a single, distinct point can be added under following conditions
1. the distance between two integers is greater than one, and
2. the number of points is not greater than 2 because then it would be impossible to place an integer between three points

## [🔗File](2004A.cpp)

## Code Snippet 
```cpp
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
```