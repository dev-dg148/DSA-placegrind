/*
 * Problem: Minimum Cost of Buying Candies With Discount (LeetCode 2144)
 * Concept: Greedy, Sorting
 * Time Complexity: O(N log N) - Due to sorting
 * Space Complexity: O(1) - Constant space used
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        sort(cost.begin(), cost.end());
        int minc = 0;
        
        
        for (int i = cost.size() - 1; i >= 0; i = i - 3) {
            
            minc += cost[i];
            
            
            if (i - 1 >= 0) {
                minc += cost[i - 1];
            }
            
        }
        
        return minc;
    }
};