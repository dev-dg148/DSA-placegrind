/*
 * Problem: Remove Element (LeetCode 27)
 * Concept: Arrays / Two Pointers
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};