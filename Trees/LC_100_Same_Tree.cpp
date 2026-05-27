/*
 * Problem: Same Tree (LeetCode 100)
 * Concept: Tree Traversal (DFS)
 * Time Complexity: O(N) - Where N is the number of nodes in the tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};