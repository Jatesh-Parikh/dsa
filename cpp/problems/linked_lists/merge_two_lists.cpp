struct Node {
    int data;
    Node *next;

    Node(): data(0), next(nullptr) {}
    Node(int data): data(data), next(nullptr) {}
    Node(int data, Node *next): data(data), next(next) {}
};

class Solution {
    public:
        // Time Complexity - O(n1 + n2)
        // Space Complexity - O(1)
        Node *merge_two_lists(Node *list1, Node *list2) {
            Node *t1 = list1;
            Node *t2 = list2;
            Node *dummy_node = new Node(-1);
            Node *temp = dummy_node;

            while (t1 && t2) {
                if (t1->data < t2->data) {
                    temp->next = t1;
                    temp = t1;
                    t1 = t1->next;
                } else {
                    temp->next = t2;
                    temp = t2;
                    t2 = t2->next;
                }
            }

            if (t1) temp->next = t1;
            else temp->next = t2; 

            Node *head = dummy_node->next;
            delete dummy_node;
            return head;
        }
};