struct Node {
    int data;
    Node *next;

    Node(): data(0), next(nullptr) {}
    Node(int data): data(data), next(nullptr) {}
    Node(int data, Node *next): data(data), next(next) {}
};

class Solution {
    private:
        int find_length(Node *slow, Node *fast) {
            int count = 1;
            fast = fast->next;
            while (slow != fast) {
                fast = fast->next;
                count++;
            }

            return count;
        }

    public:
        // Time Complexity - O(n) 
        // Space Complexity - O(1) 
        int cycle_length(Node *head) {
            Node *slow = head;
            Node *fast = head;

            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;

                if (slow == fast) return find_length(slow, fast);
            }

            return 0;
        }
};