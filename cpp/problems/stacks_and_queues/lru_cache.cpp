#include <unordered_map>
#include <iostream>

using namespace std;

class LRUCache {
    private:
        struct Node {
            int key;
            int value;
            Node* prev;
            Node* next;

            Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {}
        };

        int capacity;
        unordered_map<int, Node*> cache;

        Node* head;
        Node* tail;

        void remove_node(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        void insert_at_front(Node* node) {
            node->next = head->next;
            node->prev = head;

            head->next->prev = node;
            head->next = node;
        }

        void move_to_front(Node* node) {
            remove_node(node);
            insert_at_front(node);
        }

        void evictLRU() {
            Node* lru = tail->prev;

            remove_node(lru);
            cache.erase(lru->key);
            delete lru;
        }

    public:
        LRUCache(int cap): capacity(cap) {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);

            head->next = tail;
            tail->prev = head;
        }

        int get(int key) {
            auto it = cache.find(key);

            if (it == cache.end()) {
                return -1;
            }

            Node* node = it->second;
            move_to_front(node);
            return node->value;
        }

        void put(int key, int value) {
            if (capacity <= 0) return;

            auto it = cache.find(key);

            if (it != cache.end()) {
                Node* node = it->second;
                node->value = value;
                move_to_front(node);
                return;
            }

            if (cache.size() == capacity) {
                evictLRU();
            }

            Node* node = new Node(key, value);
            insert_at_front(node);
            cache[key] = node;
        }

        ~LRUCache() {
            Node* current = head;

            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }

        void display() const {
            Node* current = head->next;

            while (current != tail) {
                cout << "(" << current->key << ", " << current->value << ")";
                current = current->next;
            }

            cout << '\n' ;
        }
};