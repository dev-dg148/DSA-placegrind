/*
 * Problem: Find Minimum in Rotated Sorted Array II (LeetCode 154)
 * Concept: Binary Search with Duplicates
 * Time Complexity: O(log N) avg, O(N) worst
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
        int l = 0, h = nums.size() - 1, mi = INT_MAX;
        
        while (l <= h) {
            int mid = l + (h - l) / 2;
            
            // Edge Case: Handling Duplicates
            if (nums[l] == nums[mid] && nums[mid] == nums[h]) {
                mi = min(mi, nums[l]); 
                l++;
                h--;
                continue; 
            }
            
            if (nums[l] <= nums[mid]) {
                mi = min(mi, nums[l]); 
                l = mid + 1;           
            } else {
                mi = min(mi, nums[mid]); 
                h = mid - 1;             
            }
        }
        
        return mi;
    }
};