/*
 * Problem: Invert Binary Tree (LeetCode 226)
 * Concept: Tree Traversal (Post-Order DFS)
 * Time Complexity: O(N) - Every node is visited once
 * Space Complexity: O(H) - Recursion stack space where H is the height of the tree
 */

#include <iostream>

using namespace std;

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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        
        invertTree(root->left);
        invertTree(root->right);
        
        TreeNode* newL = root->left;
        root->left = root->right;
        root->right = newL;
        
        return root;        
    }
};