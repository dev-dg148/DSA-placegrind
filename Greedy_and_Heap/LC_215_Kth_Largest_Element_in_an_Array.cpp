/*
 * Problem: Kth Largest Element in an Array (LeetCode 215)
 * Concept: Min-Heap (Priority Queue)
 * Time Complexity: O(N * log K) - Efficiently maintains a heap of size K
 * Space Complexity: O(K) - Heap stores at most K elements at any time
 */

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            
            
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
       
        return pq.top();
    }
};