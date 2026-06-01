/*
 * Problem: Binary Tree Right Side View (LeetCode 199)
 * Concept: Tree Traversal (DFS - Right before Left)
 * Time Complexity: O(N) - Every node is visited exactly once
 * Space Complexity: O(H) - Recursion stack space where H is the height of the tree
 */

#include <iostream>
#include <vector>

using namespace std;

// Struct for local VS Code execution
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void right(TreeNode* root, int level, vector<int>& rsv) {
        if (!root) return;
        
        
        if (level == rsv.size()) {
            rsv.push_back(root->val);
        }
        
        
        right(root->right, level + 1, rsv);
        right(root->left, level + 1, rsv);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rsv;
        right(root, 0, rsv);
        return rsv;
    }
};