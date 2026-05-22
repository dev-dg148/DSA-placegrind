/*
 * Problem: Letter Combinations of a Phone Number (LeetCode 17)
 * Concept: Backtracking
 * Time Complexity: O(4^N * N) - Where N is the length of digits.
 * Space Complexity: O(N) - Recursion stack space.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // PRO TIP: Lookup table banao if-else ke bajaye. 
    // Index 2 pe "abc", Index 3 pe "def", etc.
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl", 
        "mno", "pqrs", "tuv", "wxyz"
    };

    void letcomb(int idx, vector<string>& anstring, string& digits, string& s) {
        // Base Case
        if (idx == digits.size()) {
            anstring.push_back(s);
            return;
        }

        // Current digit ko integer mein convert karo (e.g., '2' -> 2)
        int number = digits[idx] - '0';
        string letters = pad[number]; // Seedha lookup table se letters nikal lo

        // Tera wahi perfect Backtracking logic
        for (int j = 0; j < letters.size(); j++) {
            s.push_back(letters[j]);               // 1. Choose
            letcomb(idx + 1, anstring, digits, s); // 2. Explore
            s.pop_back();                          // 3. Un-choose
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> anstring;
        
        // Edge Case: Agar input empty hai toh seedha return karo
        if (digits.length() == 0) return anstring;

        string s = "";
        letcomb(0, anstring, digits, s);
        
        return anstring;
    }
};