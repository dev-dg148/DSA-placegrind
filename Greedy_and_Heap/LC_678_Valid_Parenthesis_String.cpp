/*
 * Problem: Valid Parenthesis String (LeetCode 678)
 * Concept: Greedy (Range of Open Brackets)
 * TC: O(N) - Single pass through the string.
 * SC: O(1) - Constant space used.
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int ma = 0; // Maximum possible open brackets
        int mi = 0; // Minimum required open brackets
        
        for (char c : s) {
            if (c == '(') {
                ma++;
                mi++;
            } else if (c == ')') {
                ma--;
                mi--;
            } else if (c == '*') {
                ma++; // Treat '*' as '('
                mi--; // Treat '*' as ')'
            }
            
           
            if (ma < 0) {
                return false;
            }
            
            // Minimum required open brackets can't drop below 0
            // If it does, it means we tried to use '*' as ')' but we didn't need to
            if (mi < 0) {
                mi = 0;
            }
        }
        
        
        return mi == 0;
    }
};