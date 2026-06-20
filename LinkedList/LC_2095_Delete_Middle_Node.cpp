/*
 * Problem: Delete the Middle Node of a Linked List (LeetCode 2095)
 * Concept: Linked List, Tortoise and Hare (Micro-Optimized)
 * TC: O(N) - N/2 iterations mathematically.
 * SC: O(1) - Only 2 pointers (slow and fast) used.
 */

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        
        ListNode* s = head;
        // Fast starts 2 steps ahead to make slow stop exactly BEFORE the middle node
        ListNode* f = head->next->next; 
        
        while (f != NULL && f->next != NULL) {
            s = s->next;
            f = f->next->next;
        }
        
        
        ListNode* de = s->next;
        s->next = de->next; 
        
        delete (de); 
        
        return head;
    }
};