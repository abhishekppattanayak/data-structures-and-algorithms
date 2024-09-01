// 1996B Scale

#include <iostream>
#include <vector>
using namespace std;

void scaleGrid(int n, vector<vector<char>>& grid, int k) {
    for (int i=0; i<n; i+=k) {
        for (int j=0; j<n; j+=k) {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}

int main() {
    
    int t;
    cin>>t;
    
    for (int iter=0; iter<t; ++iter) {
        int n, k;
        cin>>n>>k;
        
        vector<vector<char>> grid(n, vector<char>(n));
        
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                cin>>grid[i][j];
        
        scaleGrid(n, grid, k);
        
    }
    
    return 0;
}