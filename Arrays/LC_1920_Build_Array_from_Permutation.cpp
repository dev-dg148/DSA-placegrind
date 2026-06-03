/*
 * Problem: Build Array from Permutation (LeetCode 1920)
 * Concept: Arrays
 * Time Complexity: O(N)
 * Space Complexity: O(N) - For the new answer array
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
      
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++) {
          
            ans[i] = nums[nums[i]];
        }
        
        return ans;
    }
};