/*
 * Problem: Next Greater Element I (LeetCode 496)
 * Concept: Monotonic Stack + Hash Map
 * Time Complexity: O(N + M)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> s;
        int n = nums2.size();
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums2[i] >= s.top()) {
                s.pop();
            }
            
            if (s.empty()) {
                mp[nums2[i]] = -1;
            } else {
                mp[nums2[i]] = s.top();
            }
            
            s.push(nums2[i]);
        }
        
        vector<int> ans;
        ans.reserve(nums1.size()); 
        
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }
        
        return ans;
    }
};