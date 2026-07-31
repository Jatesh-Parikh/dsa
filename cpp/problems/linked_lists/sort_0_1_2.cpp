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
        Node *sort_0_1_2(Node *head) {
            if (head == nullptr || head->next == nullptr) return head;
            Node *zero_head = new Node(-1);
            Node *one_head = new Node(-1);
            Node *two_head = new Node(-1);

            Node *temp = head;

            Node *zero = zero_head;
            Node *one = one_head;
            Node *two = two_head;

            while (temp) {
                if (temp->data == 0) {
                    zero->next = temp;
                    zero = temp;
                } else if (temp->data == 1) {
                    one->next = temp;
                    one = temp;
                } else {
                    two->next = temp;
                    two = temp;
                }
                temp = temp->next;
            }

            zero->next = one_head->next ? one_head->next : two_head->next;
            one->next = two_head->next;
            two->next = nullptr;

            Node *new_head = zero_head->next;

            delete zero_head;
            delete one_head;
            delete two_head;

            return new_head;
        }
};