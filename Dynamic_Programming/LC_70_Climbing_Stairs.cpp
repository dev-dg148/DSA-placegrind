/*
 * Problem: Climbing Stairs (LeetCode 70)
 * Concept: 1D Dynamic Programming (Space Optimized Tabulation)
 * TC: $O(N)$ - Linear time to calculate the nth step.
 * SC: $O(1)$ - Constant space, no extra memory used (only 3 variables).
 */

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        
        int prev2 = 1; 
        int prev1 = 1; 
        int curr;
        
        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2; 
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};