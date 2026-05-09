/*
 * Problem: Pascal's Triangle (LeetCode 118)
 * Concept: Arrays / Math (Combinatorics / nCr)
 * Time Complexity: O(N^2)
 * Space Complexity: O(1) (excluding output array)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> genpascal(int n) {
        vector<int> ansr;
        long long ansrow = 1; 
        ansr.push_back(ansrow);
        
        for (int i = 1; i < n; i++) {
            ansrow = ansrow * (n - i);
            ansrow = ansrow / i;
            ansr.push_back(ansrow);
        }
        return ansr;
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(genpascal(i));
        }
        return ans;
    }
};