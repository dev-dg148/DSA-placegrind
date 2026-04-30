/*
 * Problem: Subarray Sum Equals K (LeetCode 560)
 * Concept: Arrays / Prefix Sum / Hash Map
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0, count = 0;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            count += mp[sum - k];
            mp[sum]++;
        }
        return count;
    }
};