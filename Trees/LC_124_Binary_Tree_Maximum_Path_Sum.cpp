/*
 * Problem: Binary Tree Maximum Path Sum (LeetCode 124)
 * Concept: Tree Traversal (DFS)
 * Time Complexity: O(N) - Every node is visited exactly once
 * Space Complexity: O(H) - Recursion stack space where H is the height of the tree
 */

#include <iostream>
#include <algorithm>
#include <climits>

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
    int maxpath(TreeNode* root, int& mapa) {
        if (!root) 
            return 0;
            
        // Ignore negative paths by comparing with 0
        int lmp = max(0, maxpath(root->left, mapa));
        int rmp = max(0, maxpath(root->right, mapa));
        
        // Update the maximum path sum found so far
        mapa = max(mapa, lmp + rmp + root->val);
        
        // Return the max path sum extending to the parent
        return max(lmp, rmp) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int mapa = INT_MIN;
        maxpath(root, mapa);
        return mapa;
    }
};