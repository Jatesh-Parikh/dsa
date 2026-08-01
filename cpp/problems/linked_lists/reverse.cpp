struct Node {
    int data;
    Node *next;

    Node(): data(0), next(nullptr) {}
    Node(int data): data(data), next(nullptr) {}
    Node(int data, Node *next): data(data), next(next) {}
};

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        Node *reverse_iterative(Node *head) {
            Node *temp = head;
            Node *prev = nullptr;
            
            while (temp) {
                Node *front = temp->next;
                temp->next = prev;
                prev = temp;
                temp = front;
            }

            return prev;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(n)
        Node *reverse_recursive(Node *head) {
            if (head == nullptr || head->next == nullptr) return head;

            Node *new_head = reverse_recursive(head->next);

            Node *front = head->next;
            front->next = head;
            head->next = nullptr;
            return new_head;
        }
};