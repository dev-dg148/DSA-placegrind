/*
 * Problem: Combination Sum (LeetCode 39)
 * Concept: Backtracking / Depth-First Search
 * Time Complexity: O(N^(T/M)) - Where N is candidates count, T is target, M is min element
 * Space Complexity: O(T/M) - Maximum depth of the recursion stack
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<int>& candidates, int target, int index, vector<int>& temp, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                temp.push_back(candidates[i]);
                // Pass 'i' again because the same element can be reused
                solve(candidates, target - candidates[i], i, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(candidates, target, 0, temp, ans);
        
        return ans;
    }
};