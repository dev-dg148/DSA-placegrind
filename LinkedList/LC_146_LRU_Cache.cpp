/*
 * Problem: LRU Cache (LeetCode 146)
 * Concept: Doubly Linked List + Hash Map
 * Time Complexity: O(1) for both get() and put() operations
 * Space Complexity: O(K) where K is the capacity of the cache
 */

#include <iostream>
#include <unordered_map>

using namespace std;

static const int fast_io = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class LRUCache {
public:
    struct Node {
        int key, val;
        Node *next, *prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };
    
    void delnode(Node* node) {
        Node* prevde = node->prev;
        Node* afterde = node->next;
        prevde->next = afterde;
        afterde->prev = prevde;
    }
    
    void insertafthead(Node* node) {
        Node* currafthead = head->next;
        head->next = node;
        node->next = currafthead;
        node->prev = head;
        currafthead->prev = node;
    }
    
    unordered_map<int, Node*> mp;
    int capacity;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        mp.clear();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        delnode(node);
        insertafthead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            delnode(node);
            insertafthead(node);
        } else {
            if (mp.size() == capacity) {
                Node* node = tail->prev;
                mp.erase(node->key);
                delnode(node);
                delete node;
            }
            Node* node = new Node(key, value);
            mp[key] = node;
            insertafthead(node);
        }
    }
};