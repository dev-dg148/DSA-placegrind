/*
 * Problem: Merge Intervals (LeetCode 56)
 * Concept: Sorting + Linear Traversal
 * Time Complexity: O(N log N)
 * Space Complexity: O(N) for result
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        // Sorting based on start time
        sort(intervals.begin(), intervals.end()); 
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++) {
            // Agar current interval ka start, pichle ke end se chota hai -> Merge
            if(intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }
            // Warna naya interval push karo
            else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};