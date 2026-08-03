struct Node {
    int data;
    Node *next;
    Node *child;

    Node(): data(0), next(nullptr), child(nullptr) {}
    Node(int data): data(data), next(nullptr), child(nullptr) {}
    Node(int data, Node *next): data(data), next(next), child(nullptr) {}
    Node(int data, Node *next, Node *child): data(data), next(next), child(child) {}
};

class Solution {
    private:
        Node *merge(Node *list1, Node *list2) {
            Node *dummy_node = new Node(-1);
            Node *res = dummy_node;

            while (list1 && list2) {
                if (list1->data < list2->data) {
                    res->child = list1;
                    res = list1;
                    list1 = list1->child;
                } else {
                    res->child = list2;
                    res = list2;
                    list2 = list2->child;
                }
                res->next = nullptr;
            }

            if (list1) res->child = list1;
            else res->child = list2;

            return dummy_node->child;
        }

    public:
        // Time Complexity - O(n ^ 2 * m)
        // Space Complexity - O(n)
        Node *flatten_ll(Node *head) {
            if (head == nullptr || head->next == nullptr) return head;

            Node *merged_head = flatten_ll(head->next);
            return merge(head, merged_head);
        }
};