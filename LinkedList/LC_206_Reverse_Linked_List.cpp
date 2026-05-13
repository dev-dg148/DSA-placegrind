/*
 * Problem: Reverse Linked List (LeetCode 206)
 * Concept: Linked List / Iterative Reversal
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while (curr != NULL) {
            ListNode* nextNode = curr->next; 
            curr->next = prev;               
            prev = curr;                     
            curr = nextNode;                 
        }
        
        return prev;
    }
};