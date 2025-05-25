/*
    Title: LRU Cache Implementation
    
    Problem Statement:
        Implement an LRU (Least Recently Used) Cache with get and put operations in O(1) time.

    Approach: 
        - Use a doubly linked list to store the order of usage.
        - Use an unordered_map to store key -> node mappings for O(1) access.

    Time Complexity: 
        O(1) for both get and put.
        
    Space Complexity:
        O(capacity) for storing cache items.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <unordered_map>
using namespace std;

// Definition of a node
class Node {
public:
    int data;
    int key;
    Node* next;
    Node* prev;

    Node(int key1, int val) {
        key = key1;
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void remove_node(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void add_node(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }

        Node* node = cache[key];
        remove_node(node);
        add_node(node);

        return node->data;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            Node* existingNode = cache[key];
            remove_node(existingNode);
            delete existingNode;
            cache.erase(key);
        }

        if (cache.size() >= capacity) {
            Node* lru_node = tail->prev;
            remove_node(lru_node);
            cache.erase(lru_node->key);
            delete lru_node;
        }

        Node* newNode = new Node(key, value);
        add_node(newNode);
        cache[key] = newNode;
    }

    ~LRUCache() {
        // Clean up the linked list and map
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

// Driver code for testing
int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // returns 1
    cache.put(3, 3);              // evicts key 2
    cout << cache.get(2) << endl; // returns -1 (not found)
    cache.put(4, 4);              // evicts key 1
    cout << cache.get(1) << endl; // returns -1 (not found)
    cout << cache.get(3) << endl; // returns 3
    cout << cache.get(4) << endl; // returns 4

    return 0;
}
