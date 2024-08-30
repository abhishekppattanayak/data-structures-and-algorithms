// 2010A Alternating Sum of Numbers

#include <iostream>
using namespace std;

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

int main() {
    int t;
    cin>>t;
    
    for (int i=0; i<t; ++i) {
        cout<<alternatingSumOfNumbers()<<endl;
    }

    return 0;
}