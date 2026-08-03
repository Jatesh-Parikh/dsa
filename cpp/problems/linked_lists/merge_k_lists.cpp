#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(): data(0), next(nullptr) {}
    Node(int data): data(data), next(nullptr) {}
    Node(int data, Node *next): data(data), next(next) {}
};

class Solution {
    public:
        // Time Complexity - O((nk) * logk), where n is the number of nodes per linked list and k is the number of linked lists
        // The min heap will at most store k elements
        // Space Complexity - O(k)
        Node *merge_k_lists(vector<Node *>& list_array) {
            priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> pq;

            for (int i = 0; i < list_array.size(); i++) {
                if (list_array[i]) {
                    pq.push({ list_array[i]->data, list_array[i] });
                }
            }

            Node *dummy_node = new Node(-1);
            Node *temp = dummy_node;

            while (!pq.empty()) {
                auto it = pq.top();
                pq.pop();
                
                if (it.second->next) {
                    pq.push({ it.second->next->data, it.second->next });
                }
                
                temp->next = it.second;
                temp = temp->next;
            }

            Node *head = dummy_node->next;
            delete dummy_node;
            return head;
        }
};