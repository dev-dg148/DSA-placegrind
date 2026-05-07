/*
 * Problem: Two Sum (LeetCode 1)
 * Concept: Arrays / Hashing (One-Pass)
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            int want = target - nums[i];
            
            if (mp.find(want) != mp.end()) {
                return {mp[want], i}; 
            }
            
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};