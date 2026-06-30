/*
 * Problem: Find the Pivot Integer (LeetCode 2485)
 * Concept: Math (Optimization)
 * TC: $O(1)$ - Constant time to compute the total sum and its square root.
 * SC: $O(1)$ - Constant space, completely avoiding prefix/suffix arrays.
 */

#include <cmath>

class Solution {
public:
    int pivotInteger(int n) {
        int total = n * (n + 1) / 2;
        int pivot = sqrt(total);
        
        if (pivot * pivot == total) {
            return pivot;
        }
        
        return -1;
    }
};