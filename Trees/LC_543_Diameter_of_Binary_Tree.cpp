/*
 * Problem: Diameter of Binary Tree (LeetCode 543)
 * Concept: Tree Traversal (DFS)
 * Time Complexity: O(N) - Every node is visited exactly once
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
    int hei(TreeNode* root, int& dia) {
        if (!root)
            return 0;
            
        int lh = hei(root->left, dia);
        int rh = hei(root->right, dia);
        
        dia = max(dia, lh + rh);
        
        return max(lh, rh) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        hei(root, dia);
        return dia;
    }
};