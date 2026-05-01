/*
 * Problem: Running Sum of 1d Array (LeetCode 1480)
 * Concept: Arrays / Prefix Sum
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] + nums[i - 1];
        }
        return nums;
    }
};