# 2010A Alternating Sum of Numbers

You can checkout the problem statemment [here](https://codeforces.com/problemset/problem/2010/A).

## Thought Process

First, start with plus and alternate with minus so even indices will be added and odd ones will be subtracted.

## [🔗Solution File](solution.cpp)

## Code Snippet 
```cpp
// cpp
int alternatingSumOfNumbers() {
    int n;
    cin>>n;
    int sum = 0;
    for (int i=0; i<n; ++i) {
        int x;
        cin>>x;
        if (i%2)
            sum -= x;
        else
            sum += x;
    }
    return sum;
}
```