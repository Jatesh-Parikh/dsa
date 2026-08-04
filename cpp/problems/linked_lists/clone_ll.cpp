struct Node {
    int data;
    Node *next;
    Node *random;

    Node(): data(0), next(nullptr), random(nullptr) {}
    Node(int data): data(data), next(nullptr), random(nullptr) {}
    Node(int data, Node *next): data(data), next(next), random(nullptr) {}
    Node(int data, Node *next, Node *random): data(data), next(next), random(random) {}
};


// 1. Insert copy nodes in between
// 2. Connect random pointers
// 3. Connect next pointers 
class Solution {
    private:
        void insert_copy_nodes(Node *head) {
            Node *temp = head;

            while (temp) {
                Node *copy = new Node(temp->data);
                copy->next = temp->next; 
                temp->next = copy;
                temp = temp->next->next;
            }
        }

        void connect_random_pointers(Node *head) {
            Node *temp = head;

            while (temp) {
                Node *copy = temp->next;
                if (temp->random) copy->random = temp->random->next;
                else copy->random = nullptr;
                temp = temp->next->next;
            }
        }

        Node *connect_next_pointers(Node *head) {
            Node *dummy_node = new Node(-1);
            Node *res = dummy_node;
            Node *temp = head;

            while (temp) {
                res->next = temp->next;
                temp->next = temp->next->next;
                res = res->next;
                temp = temp->next;
            }

            Node *new_head = dummy_node->next;
            delete dummy_node;
            return new_head; 
        }

    public:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        Node *clone_ll(Node *head) {
            if (!head) return head;

            insert_copy_nodes(head);
            connect_random_pointers(head);
            return connect_next_pointers(head);
        }
};