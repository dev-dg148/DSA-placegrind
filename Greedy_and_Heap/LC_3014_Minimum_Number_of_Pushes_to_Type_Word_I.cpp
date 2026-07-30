/*
 * Problem: Minimum Number of Pushes to Type Word I (LeetCode 3014)
 * Concept: Math / Greedy Approach
 * Time Complexity: O(1) // Loop runs at most 4 times (max 26 letters)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        if (word.length() <= 8) { 
            return word.length();
        }
        int minpush = 0, c = 1;
        int w = word.length();
        
        while (w > 0) {
            if (w > 8) {
                minpush += 8 * c;
                c++;
            } else {
                minpush += w * c;
            }
            w -= 8;
        }
        return minpush;
    }
};