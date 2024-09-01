// 2010B Three Brothers

#include <iostream>
using namespace std;

int lateBrother() {
    int a, b;
    cin>>a>>b;
    return 6-a-b;
}

int main() {
    cout<<lateBrother();
    return 0;
}