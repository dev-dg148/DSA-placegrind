/*
 * Problem: Palindrome Linked List (LeetCode 234)
 * Concept: Fast/Slow Pointers + Reverse + Compare
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

#include <iostream>

using namespace std;

// VS Code local definition for ListNode to avoid errors
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
       
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;

      
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        
        // Odd length hai toh middle element ko reverse se pehle skip karo
        if (fast) {
            slow = slow->next;
        }

        
        ListNode* prev = NULL;
        while (slow) {
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

       
        while (prev) {
            if (head->val != prev->val) return false;
            head = head->next;
            prev = prev->next;
        }

        return true;
    }
};