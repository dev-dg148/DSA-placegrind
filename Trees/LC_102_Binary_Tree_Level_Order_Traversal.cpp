/*
 * Problem: Binary Tree Level Order Traversal (LeetCode 102)
 * Concept: Tree Traversal (Breadth-First Search / BFS)
 * Time Complexity: O(N) - Every node is visited exactly once
 * Space Complexity: O(N) - The queue can hold up to N/2 nodes at the deepest level
 */

#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
            
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int s = q.size();
            vector<int> a;
            for (int i = 0; i < s; i++) {
                TreeNode* curr = q.front();
                a.push_back(curr->val);
                q.pop();
                
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            ans.push_back(a);
        }
        return ans;
    }
};