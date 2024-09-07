# 1945 Sum of Digits of String After Convert

You can checkout the problem statemment [here](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/).

## Thought Process

We simulate the process as it is being told. But, don't convert the string `s` as a whole to string of numbers because it may cause integer overflow. Instead, in the first for loop itself, we parse the letters to integers individually.

## [🔗Solution File](solution.cpp)

## Code Snippet 
```cpp
// cpp
class Solution {
public:
    int getLucky(string s, int k) {
        // time complexity : O(n+k)
        // space complexity : O(1)
        int number = 0;
        for (char &c: s) {
            int i = c-'a'+1;
            while (i) {
                number += i%10;
                i /= 10;
            }
        }
        --k;
        while (k > 0) {
            if (number < 10)
                break;
            int sum = 0;
            while (number) {
                sum += number%10;
                number /= 10;
            }
            number = sum;
            --k;
        }
        return number;
    }
};
```