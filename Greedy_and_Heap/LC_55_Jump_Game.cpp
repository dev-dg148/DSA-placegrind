/*
 * Problem: Jump Game (LeetCode 55)
 * Concept: Greedy Algorithm (Max Reach / Fuel Tank)
 * TC: O(N) - Single pass through the array.
 * SC: O(1) - Constant space used.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0; 
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (i > maxReach) {
                return false;
            }
            
           
            maxReach = max(maxReach, i + nums[i]);
        
            if (maxReach >= nums.size() - 1) {
                return true;
            }
        }
        
        return true;
    }
};