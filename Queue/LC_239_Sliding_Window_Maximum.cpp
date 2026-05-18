/*
 * Problem: Sliding Window Maximum (LeetCode 239)
 * Concept: Monotonic Deque (Sliding Window)
 * Time Complexity: O(N) - Each element is pushed and popped at most once
 * Space Complexity: O(K) - Deque stores at most K elements
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; 
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
           
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
           
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            
            dq.push_back(i);
            
            // Once the first window is formed (i >= k - 1), record the maximum
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]); 
            }
        }
        
        return ans;
    }
};