/*
 * Problem: Merge k Sorted Lists (LeetCode 23)
 * Concept: Brute Force using Max-Heap
 * Time Complexity: O(N log N) - Pushing all N elements across all lists into the heap
 * Space Complexity: O(N) - Storing N elements in the heap and allocating N new nodes
 */

#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list. (UNCOMMENTED FOR LOCAL IDE)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int> maxhp;
        
        // Step 1: Traverse all linked lists and push every node's value into the Max-Heap
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp != nullptr) {
                maxhp.push(temp->val);
                temp = temp->next;
            }
        }
        
        // Step 2: Guard rail for completely empty inputs
        if (maxhp.empty()) {
            return nullptr;
        }
        
        // Step 3: Extract from Max-Heap and insert at the head to build ascending list
        ListNode* ans = new ListNode(maxhp.top());
        ans->next = nullptr;
        maxhp.pop();
        
        while (!maxhp.empty()) {
            ListNode* add = new ListNode(maxhp.top());
            maxhp.pop();
            
            add->next = ans; 
            ans = add;       
        }
        
        return ans;
    }
};