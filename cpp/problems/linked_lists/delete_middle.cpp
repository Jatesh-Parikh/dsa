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
        Node *delete_middle(Node *head) {
            if (head == nullptr) return nullptr;
            if (head->next == nullptr) {
                delete head;
                return nullptr;
            }

            Node *slow = head;
            Node *fast = head;
            fast = fast->next->next;

            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }

            Node *middle = slow->next;
            slow->next = slow->next->next;
            delete middle;
            return head;
        }
};