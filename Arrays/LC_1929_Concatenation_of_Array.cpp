/*
 * Problem: Concatenation of Array (LeetCode 1929)
 * Concept: Arrays
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size(); 
        for(int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};