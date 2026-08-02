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
        Node *cycle_start_node(Node *head) {
            Node *slow = head;
            Node *fast = head;

            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;

                if (fast == slow) {
                    slow = head;
                    while (fast != slow) {
                        slow = slow->next;
                        fast = fast->next;
                    }
                    return slow;
                }
            }

            return nullptr;
        }
};