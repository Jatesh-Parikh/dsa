#include <vector>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(): data(0), next(nullptr), prev(nullptr) {}
    Node(int data): data(data), next(nullptr), prev(nullptr) {}
    Node(int data, Node *next): data(data), next(next), prev(nullptr) {}
    Node(int data, Node *next, Node *prev): data(data), next(next), prev(prev) {}
};

class Solution {
    private:
        Node *find_tail(Node *head) {
            Node *tail = head;
            
            while (tail->next) {
                tail = tail->next;
            }

            return tail;
        }
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        vector<pair<int, int>> find_pairs(Node *head, int k) {
            vector<pair<int, int>> ans;
            if (head == nullptr) return ans;
            
            Node *left = head; 
            Node *right = find_tail(head);

            while (left->data < right->data) {
                if (left->data + right->data == k) {
                    ans.push_back({ left->data, right->data });
                    left = left->next;
                    right = right->prev;
                } else if (left->data + right->data > k) {
                    right = right->prev;
                } else left = left->next;
            }

            return ans;
        }
};