/*
 * Problem: Process String with Special Operations I (LeetCode 3612)
 * Concept: String Manipulation, Simulation
 * TC: O(N * M) - Where N is the length of the input string and M is the dynamic length of the processed string.
 * SC: O(M) - Space required to store the modified string at any given point.
 */

#include <iostream>
#include <string>
#include <algorithm> // For std::reverse

using namespace std;

class Solution {
public:
    string processStr(string s) {
        string sc = "";
        
        // C++98 compatible traditional for-loop
        for (int i = 0; i < s.length(); i++) {
            char c = s[i]; // Get current character
            
            // Check for special operation characters
            if (c == '*' || c == '#' || c == '%') {
                if (c == '#') {
                    // Double the current string
                    sc.append(sc);
                } else if (c == '%') {
                    // Reverse the current string
                    reverse(sc.begin(), sc.end());
                } else {
                    // Behave like a backspace: remove the last character safely using erase
                    if (!sc.empty()) {
                        sc.erase(sc.length() - 1);
                    }
                }
            } else {
                // Normal character, just append using += operator
                sc += c;
            }
        }
        
        return sc;
    }
};