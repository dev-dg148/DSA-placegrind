// Problem: Permutations (LeetCode 46)
// Concept: Backtracking (Swap Optimized Method)
// Time Complexity: O(N! * N)
// Space Complexity: O(N)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int idx) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);       // Choose
            
            solve(nums, ans, idx + 1);      // Explore
            
            swap(nums[idx], nums[i]);       // Un-choose (Backtrack)
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, ans, 0);
        return ans;
    }
};