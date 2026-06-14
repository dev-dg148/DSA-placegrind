/*
 * Problem: Score of a String (LeetCode 3110)
 * Concept: String Traversal, ASCII Math
 * TC: O(N) - Where N is the length of the string. We traverse it once.
 * SC: O(1) - Constant space used.
 */

#include <iostream>
#include <string>
#include <cmath> 

using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        
        for (int i = 0; i < s.length() - 1; i++) {
            score += abs(s[i] - s[i + 1]);
        }
        
        return score;
    }
};