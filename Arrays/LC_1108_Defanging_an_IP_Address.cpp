/*
 * Problem: Defanging an IP Address (LeetCode 1108)
 * Concept: Strings
 * Time Complexity: O(N)
 * Space Complexity: O(N) // O(1) auxiliary space, but O(N) for the output string
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string s = "";
        // Reserving max possible space to avoid memory reallocation overhead
        s.reserve(address.size() + 6); 
        
        for (char cs : address) {
            if (cs == '.') {
                s += "[.]";
            } else {
                s.push_back(cs);
            }
        }
        return s;
    }
};