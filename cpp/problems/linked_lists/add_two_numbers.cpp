struct Node {
    int data;
    Node *next;

    Node(): data(0), next(nullptr) {} 
    Node(int data): data(data), next(nullptr) {} 
    Node(int data, Node *next): data(data), next(next) {} 
};

// Least significant digit first
class Solution {
    public:
        // Time Complexity - O(max(n, m))
        // Space Complexity - O(1)
        Node *add_two_numbers(Node *num1, Node *num2) {
            Node *dummy_head = new Node(-1);
            Node *curr = dummy_head;
            Node *t1 = num1;
            Node *t2 = num2;
            int carry = 0;

            while (t1 != nullptr || t2 != nullptr) {
                int sum = carry;
                if (t1) sum += t1->data;
                if (t2) sum += t2->data;

                Node *new_node = new Node(sum % 10);
                carry = sum / 10;

                curr->next = new_node;
                curr = curr->next;

                if (t1) t1 = t1->next;
                if (t2) t2 = t2->next;
            }

            if (carry) {
                Node *new_node = new Node(carry);
                curr->next = new_node;
            }

            return dummy_head->next;
        }
};