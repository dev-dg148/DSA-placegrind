/*
 * Problem: Serialize and Deserialize Binary Tree (LeetCode 297 - Hard)
 * Concept: Tree Traversal (BFS / Level Order), String Parsing
 * Time Complexity: O(N) for both serialization and deserialization
 * Space Complexity: O(N) for Queue and String
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

// Struct for local VS Code execution
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return ""; 
            
        string s = ""; 
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (curr == NULL) {
                s.append("#,");
            } else {
                s.append(to_string(curr->val) + ',');
               
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return NULL;
            
        stringstream s(data);
        string st;
        
        // Get the root value
        getline(s, st, ',');
        TreeNode* root = new TreeNode(stoi(st));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* ode = q.front();
            q.pop();
            
           
            getline(s, st, ',');
            if (st == "#") {
                ode->left = NULL;
            } else {
                TreeNode* leftode = new TreeNode(stoi(st));
                ode->left = leftode;
                q.push(leftode);
            }
            
           
            getline(s, st, ',');
            if (st == "#") {
                ode->right = NULL;
            } else {
                TreeNode* rightode = new TreeNode(stoi(st));
                ode->right = rightode; 
                q.push(rightode);
            }
        }
        return root;
    }
};