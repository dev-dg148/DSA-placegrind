/*
 * Problem: Palindrome Partitioning (LeetCode 131)
 * Concept: Backtracking
 * Time Complexity: O(N * 2^N)
 * Space Complexity: O(N) 
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void cutpart(int idx, vector<vector<string>>& pp, vector<string>& sp, const string& s) {
       
        if (idx == s.length()) {
            pp.push_back(sp);
            return;
        }
        
        
        for (int i = idx; i < s.length(); i++) {
            if (isPalindrome(s, idx, i)) {
                
                sp.push_back(s.substr(idx, i - idx + 1));
                
                
                cutpart(i + 1, pp, sp, s);
                
                
                sp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> pp;
        vector<string> sp;
        
        cutpart(0, pp, sp, s);
        
        return pp;
    }
};