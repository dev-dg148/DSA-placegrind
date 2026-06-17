/*
 * Problem: Palindrome Number (LeetCode 9)
 * Concept: Math
 * TC: O(log10(x)) - We divide the input by 10 for every iteration.
 * SC: O(1) - Constant space used.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int r = 0;
        while (x > r) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return x == r || x == r / 10;
    }
};