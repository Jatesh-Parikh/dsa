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
        Node *remove_duplicate(Node *head) {
            Node *temp = head;

            while (temp != nullptr && temp->next != nullptr) {
                Node *next_node = temp->next;
                
                while (next_node != nullptr && next_node->data == temp->data) {
                    Node *duplicate = next_node;
                    next_node = next_node->next;
                    delete duplicate;
                }

                temp->next = next_node;
                if (next_node) next_node->prev = temp;
                temp = temp->next;
            }

            return head;
        }
};