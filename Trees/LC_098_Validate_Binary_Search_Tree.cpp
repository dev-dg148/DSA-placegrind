/*
 * Problem: Validate Binary Search Tree (LeetCode 98)
 * Concept: Tree Traversal (DFS), Binary Search Tree Properties
 * Time Complexity: O(N) - Every node is visited exactly once
 * Space Complexity: O(H) - Recursion stack space where H is the height of the tree
 */

#include <iostream>

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
    bool isvbst(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (!root) 
            return true;
            
        if (minNode != nullptr && minNode->val >= root->val) 
            return false;
        if (maxNode != nullptr && maxNode->val <= root->val) 
            return false;
            
        return isvbst(root->left, minNode, root) && isvbst(root->right, root, maxNode);
    }
    
    bool isValidBST(TreeNode* root) {
        return isvbst(root, nullptr, nullptr);
    }
};