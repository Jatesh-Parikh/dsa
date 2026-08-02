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
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        Node *delete_occurences_dll(Node *head, int k) {
            Node *temp = head;

            while (temp) {
                if (temp->data == k) {
                    if (temp == head) {
                        head = temp->next;
                    }
                    
                    Node *prev_node = temp->prev;
                    Node *next_node = temp->next;

                    if (prev_node) prev_node->next = next_node;
                    if (next_node) next_node->prev = prev_node;
                    delete temp;
                    temp = next_node;
                } else {
                    temp = temp->next;
                }
            }

            return head;
        }
};