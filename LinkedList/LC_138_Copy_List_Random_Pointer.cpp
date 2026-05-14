/*
 * Problem: Copy List with Random Pointer (LeetCode 138)
 * Concept: Linked List / Deep Copy (O(1) Space Approach)
 * Time Complexity: O(N) | Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

// VS Code local definition for Random Pointer Node
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    void insertcopy(Node* head) {
        Node* temp = head;
        while (temp) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }
    }

    void copyrandom(Node* head) {
        Node* temp = head;
        while (temp) {
            Node* copy = temp->next;
            if (temp->random) {
                copy->random = temp->random->next;
            } else {
                copy->random = NULL;
            }
            temp = temp->next->next;
        }
    }

    Node* extractcopy(Node* head) {
        Node dummy(-1); 
        Node* res = &dummy; 
        Node* temp = head;
        

        while (temp) {
            res->next = temp->next;
            temp->next = temp->next->next; 
            res = res->next;
            temp = temp->next;
        }
        return dummy.next; 
    }

    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        insertcopy(head);
        copyrandom(head);
        return extractcopy(head);
    }
};