/*
 * Problem: Minimum Number of Arrows to Burst Balloons (LeetCode 452)
 * Concept: Greedy Algorithm, Sorting Intervals
 * TC: $O(N \log N)$ - Dominated by the sorting step. The array traversal takes $O(N)$.
 * SC: $O(1)$ - Constant space, no extra memory used.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) { 
        return a[1] < b[1]; 
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end(), comp);
        
        int arrow = 1; 
        int last = points[0][1];
        
        for (int i = 1; i < points.size(); i++) {
            if (last < points[i][0]) {
                arrow++;
                last = points[i][1];
            }
        }
        
        return arrow;
    }
};