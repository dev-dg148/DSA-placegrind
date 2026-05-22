/*
 * Problem: Generate Parentheses (LeetCode 22)
 * Concept: Backtracking
 * Time Complexity: O(4^n / sqrt(n)) - Nth Catalan Number, generating only valid combinations.
 * Space Complexity: O(n) - Maximum depth of the recursion stack is 2*n.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void genpar(int o, int c, int n, vector<string>& ocs, string& s) {
        // Base Case: Jab open aur close brackets 'n' ke barabar ho jayein
        if (o == n && c == n) {
            ocs.push_back(s);
            return;
        }
        
        // Option 1: Closing bracket add karo (agar open se kam hain)
        if (o > c) {
            s.push_back(')');
            genpar(o, c + 1, n, ocs, s);
            s.pop_back(); // Un-choose (Backtrack)
        }
        
        // Option 2: Opening bracket add karo (agar limit 'n' tak nahi pohocha)
        if (o < n) {
            s.push_back('(');
            genpar(o + 1, c, n, ocs, s);
            s.pop_back(); // Un-choose (Backtrack)
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ocs;
        string s = "";
        
        genpar(0, 0, n, ocs, s);
        
        return ocs;
    }
};