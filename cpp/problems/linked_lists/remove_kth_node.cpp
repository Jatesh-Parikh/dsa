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
        Node *remove_kth_node(Node *head, int k) {
            Node *fast = head;
            Node *slow = head;

            for (int i = 0; i < k; i++) {
                fast = fast->next;
            }

            if (fast == nullptr) {
                Node *removed = head;
                head = head->next;
                delete removed;
                return head;
            }

            while (fast) {
                fast = fast->next;
                slow = slow->next;
            }

            Node *removed = slow->next;
            slow->next = slow->next->next;
            delete removed;
            return head;
        }
};