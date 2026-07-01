/*
 * Problem: Smallest Repunit Divisible by K (LeetCode 1015)
 * Concept: Modular Arithmetic & Pigeonhole Principle
 * TC: $O(K)$ - Worst case scenario involves checking up to K remainders.
 * SC: $O(1)$ - Constant space, avoiding large number storage.
 */

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        
        int remainder = 0;
        for (int i = 1; i <= k; i++) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0) return i;
        }
        return -1;
    }
};