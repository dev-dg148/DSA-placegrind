/*
 * Problem: Jump Game II (LeetCode 45)
 * Concept: Greedy Algorithm (BFS Window Approach)
 * TC: O(N) - Each element is processed exactly once in the inner loop.
 * SC: O(1) - Constant space used for pointers.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0; 
        int l = 0; 
        int r = 0; 
        
        
        while (r < nums.size() - 1) {
            int far = 0;
            
            // Check all elements in the current window [l, r] to find the farthest jump
            for (int ind = l; ind <= r; ind++) {
                far = max(ind + nums[ind], far);
            }
            
            // Shift the window to the next range
            l = r + 1;
            r = far;
            jumps++; 
        }
        
        return jumps;
    }
};