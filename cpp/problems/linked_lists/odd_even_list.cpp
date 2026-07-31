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
        Node *odd_even_list(Node *head) {
            if (head == nullptr || head->next == nullptr) return head;

            Node *odd = head; 
            Node *even = head->next;
            Node *even_head = head->next;

            while (even != nullptr && even->next != nullptr) {
                odd->next = odd->next->next;
                even->next = even->next->next;

                odd = odd->next;
                even = even->next;
            }
            odd->next = even_head;

            return head;
        }
};