/*
 * Problem: Largest Rectangle in Histogram (LeetCode 84)
 * Concept: Monotonic Stack (1-Pass Optimal Approach)
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int maxa = 0;
        
        // 1-Pass Approach: Calculate NSE and PSE on the fly
        for (int i = 0; i < n; i++) { 
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int ele = s.top();
                s.pop();
                int nse = i;
                int pse = s.empty() ? -1 : s.top();
                maxa = max(maxa, heights[ele] * (nse - pse - 1));
            }
            s.push(i);
        } 
        
        // Clear the remaining elements in the stack
        while (!s.empty()) {
            int ele = s.top();
            s.pop();
            int nse = n;
            int pse = s.empty() ? -1 : s.top();
            maxa = max(maxa, heights[ele] * (nse - pse - 1));
        }
        
        return maxa;
    }
};