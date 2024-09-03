// LeetCode 1945 Sum of Digits of String After Convert

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