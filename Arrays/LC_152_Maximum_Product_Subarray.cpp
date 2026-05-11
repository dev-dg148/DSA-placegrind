/*
 * Problem: Maximum Product Subarray (LeetCode 152)
 * Concept: Prefix & Suffix Product (Handling zeroes and negative numbers)
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double pcp = 1, sup = 1, mp = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            if (pcp == 0) pcp = 1;
            pcp *= nums[i];
            mp = max(pcp, mp);
        }
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (sup == 0) sup = 1;
            sup *= nums[i];
            mp = max(mp, sup);
        }
        
        return mp;
    }
};