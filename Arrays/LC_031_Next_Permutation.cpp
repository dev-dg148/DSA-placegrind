/*
 * Problem: Next Permutation (LeetCode 31)
 * Concept: Arrays / Math
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin() + ind + 1, nums.end());
    }
};