/*
 * Problem: Kth Smallest Element in a BST (LeetCode 230)
 * Concept: Binary Search Tree (BST), Inorder Traversal
 * Time Complexity: O(K) - Traverses only up to the Kth element (Early Exit)
 * Space Complexity: O(H) - Recursion stack space where H is the tree height
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
    void ino(TreeNode* root, int k, int& count, int& kth) {
        // Base case + Early Exit (agar kth element mil gaya toh aage mat jao)
        if (!root || count >= k)
            return;
            
        ino(root->left, k, count, kth);
        
        count++;
        if (count == k) {
            kth = root->val;
            return;
        }
        
        
        ino(root->right, k, count, kth);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int kth = 0, count = 0;
        ino(root, k, count, kth);
        return kth;
    }
};