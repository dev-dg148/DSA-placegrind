/*
 * Problem: Find Minimum in Rotated Sorted Array (LeetCode 153)
 * Concept: Binary Search
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;
        int mi = INT_MAX;
        
        while (l <= h) {
            int mid = l + (h - l) / 2;
            
            if (nums[l] <= nums[mid]) {
                mi = min(nums[l], mi); 
                l = mid + 1;           
            } else {
                mi = min(nums[mid], mi); 
                h = mid - 1;             
            }
        }
        
        return mi;
    }
};