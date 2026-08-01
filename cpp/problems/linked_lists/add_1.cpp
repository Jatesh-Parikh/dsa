struct Node {
    int data;
    Node *next;

    Node(): data(0), next(nullptr) {}
    Node(int data): data(data), next(nullptr) {}
    Node(int data, Node *next): data(data), next(next) {}
};

class Solution {
    private:
        int add_helper(Node *temp) {
            if (temp == nullptr) return 1;
            int carry = add_helper(temp->next);
            temp->data = temp->data + carry;
            if (temp->data < 10) return 0;
            temp->data = 0;
            return 1;
        }

    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        Node *add_1(Node *head) {
            int carry = add_helper(head);

            if (carry == 1) {
                Node *new_head = new Node(1);
                new_head->next = head;
                return new_head;
            }
            
            return head;
        }
};