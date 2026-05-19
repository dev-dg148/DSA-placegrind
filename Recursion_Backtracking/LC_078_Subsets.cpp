/*
 * Problem: Subsets (LeetCode 78)
 * Concept: Recursion & Backtracking (Pick / Don't Pick)
 * Time Complexity: O(N * 2^N) - 2^N subsets, taking O(N) time to push each
 * Space Complexity: O(N) - Depth of recursion stack and temporary array size
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void subgen(int idx, vector<vector<int>>& ans, vector<int>& nums, vector<int>& asub) {
        if (idx == nums.size()) {
            ans.push_back(asub);
            return;
        }
        
        // Choice 1: Not Pick
        subgen(idx + 1, ans, nums, asub);
        
        // Choice 2: Pick
        asub.push_back(nums[idx]);
        subgen(idx + 1, ans, nums, asub);
        
        // Backtrack
        asub.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> asub;
        subgen(0, ans, nums, asub); 
        return ans;
    }
};