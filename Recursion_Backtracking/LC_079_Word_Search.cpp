/*
 * Problem: Word Search (LeetCode 79)
 * Concept: Backtracking (DFS) + Advanced Pruning
 * Time Complexity: O(N * M * 4^L) mathematically, par practically O(1) jaisa fast hai pruning ki wajah se.
 * Space Complexity: O(L) 
 */

#include <vector>
#include <string>
#include <algorithm> 
using namespace std;

class Solution {
public:
    void ex(int idx, int r, int c, vector<vector<char>>& board, string& word, bool& e) {
        // Early Exit
        if (e) return; 
        
        // Base Case
        if (idx == word.length()) {
            e = true;
            return;
        }
        
        // MASTER BOUND CHECK 
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[idx]) {
            return;
        }
        
        // 1. Choose
        board[r][c] = '#'; 
        
        // 2. Explore 
        ex(idx + 1, r - 1, c, board, word, e); // Up
        ex(idx + 1, r + 1, c, board, word, e); // Down
        ex(idx + 1, r, c - 1, board, word, e); // Left
        ex(idx + 1, r, c + 1, board, word, e); // Right
        
        // 3. Un-choose
        board[r][c] = word[idx]; 
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        
        if (word.length() > m * n) return false;
        
       
        vector<int> count(256, 0); 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                count[board[i][j]]++;
            }
        }
        for (char c : word) {
            count[c]--;
            if (count[c] < 0) return false; 
        }
        
        
        
       
        
        bool e = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (e) return true;
                
                
                if (board[i][j] == word[0]) {
                    ex(0, i, j, board, word, e);
                }
            }
        }
        return e;
    }
};