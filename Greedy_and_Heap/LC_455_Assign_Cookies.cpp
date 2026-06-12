/*
 * Problem: Assign Cookies (LeetCode 455)
 * Concept: Greedy Algorithm & Two Pointers
 * Time Complexity: O(N log N + M log M) - Sorting both arrays takes the most time
 * Space Complexity: O(1) - Constant space used for pointers
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size(); // Number of children
        int n = s.size(); // Number of cookies
        
       
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int l = 0; // Pointer for children (greed)
        int r = 0; // Pointer for cookies
        
       
        while (l < m && r < n) {
           
            if (s[r] >= g[l]) {
                l++; 
            }
            
            r++;
        }
        
       
        return l;
    }
};