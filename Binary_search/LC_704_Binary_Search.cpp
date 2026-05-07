/*
 * Problem: Binary Search (LeetCode 704)
 * Concept: Arrays / Binary Search
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        
        while (l <= h) {
            // SDE optimization to prevent Integer Overflow
            int mid = l + (h - l) / 2; 
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return -1;
    }
};