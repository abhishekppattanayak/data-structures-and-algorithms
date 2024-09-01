# 1996B Scale

You can checkout the problem statemment [here](https://codeforces.com/problemset/problem/1996/B).

## Thought Process

We know a *`k x k`* block would always have same value, so we can essentially skip past *`k`* rows and columns while iterating.

## [🔗Solution File](solution.cpp)

## Code Snippet 
```cpp
void scaleGrid(int n, vector<vector<char>>& grid, int k) {
    for (int i=0; i<n; i+=k) {
        for (int j=0; j<n; j+=k) {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}
```