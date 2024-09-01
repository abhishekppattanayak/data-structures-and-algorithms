# 2010B Three Brothers
You can checkout the problem statemment [here](https://codeforces.com/problemset/problem/2010/B).

## Thought Process

All brothers are represented by the numbers `1`, `2`, `3`. And we have to find the late brother. Since, the representations are numbers, we can add or subtract them from common something to find missing. So sum of 1, 2, and 3 is 6; subtracting present brothers from 6 would give us absent brother.

## [🔗Solution File](solution.cpp)

## Code Snippet 
```cpp
// cpp
int lateBrother() {
    int a, b;
    cin>>a>>b;
    return 6-a-b;
}
```