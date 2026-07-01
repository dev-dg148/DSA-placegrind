/*
 * Problem: Ugly Number (LeetCode 263)
 * Concept: Math & Prime Factorization
 * TC: $O(\log N)$ - Because we are dividing N by prime factors 2, 3, and 5 repeatedly.
 * SC: $O(1)$ - Constant space, no extra memory used.
 */

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;
        
        return n == 1;
    }
};