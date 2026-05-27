/*
 * Problem: Maximum Depth of Binary Tree (LeetCode 104)
 * Concept: Tree Traversal (Post-Order DFS)
 * Time Complexity: O(N) - Every node is visited once
 * Space Complexity: O(H) - Recursion stack space where H is the height of the tree
 */

#include <iostream>
#include <algorithm>

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        return 1 + max(leftDepth, rightDepth);
    }
};