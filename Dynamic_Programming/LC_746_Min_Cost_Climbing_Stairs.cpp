/*
 * Problem: Min Cost Climbing Stairs (LeetCode 746)
 * Concept: 1D Dynamic Programming (Space Optimized)
 * TC: $O(N)$ - We iterate through the cost array exactly once.
 * SC: $O(1)$ - We only use two variables instead of a full DP array.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        // Base cases space optimized
        int prev2 = 0; // Represents dp[i-2]
        int prev1 = 0; // Represents dp[i-1]
        
        for (int i = 2; i <= n; i++) {
                        int curr = min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
            
           
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;  }
};