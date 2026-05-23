/*
 * Problem: Check if Array Is Sorted and Rotated (LeetCode 1752)
 * Concept: Array Linear Scan / Circular Check
 * Time Complexity: O(N) - Single pass through the array
 * Space Complexity: O(1) - No extra space used
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int c = 0; 
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                c++;
            }
        }
        
        return c <= 1; 
    }
};