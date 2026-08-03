struct Node {
    int data;
    Node *next;

    Node(): data(0), next(nullptr) {}
    Node(int data): data(data), next(nullptr) {}
    Node(int data, Node *next): data(data), next(next) {}
};

class Solution {
    private:
        // Time Complexity - O(n)
        Node *find_middle(Node *head) {
            Node *slow = head;
            Node *fast = head->next;

            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow;
        }

        // Time Complexity - O(n1 + n2) 
        Node *merge(Node *list1, Node *list2) {
            Node *dummy_node = new Node(-1);
            Node *temp = dummy_node;

            while (list1 && list2) {
                if (list1->data < list2->data) {
                    temp->next = list1;
                    temp = list1;
                    list1 = list1->next;
                } else {
                    temp->next = list2;
                    temp = list2;
                    list2 = list2->next;
                }
            }

            if (list1) temp->next = list1;
            else temp->next = list2;

            Node *head = dummy_node->next;
            delete dummy_node;
            return head;
        }

    public:
        // Time Complexity - O(n logn)
        // Space Complexity - O(logn)
        Node *sort_ll(Node *head) { 
            if (head == nullptr || head->next == nullptr) return head;

            Node *middle = find_middle(head);
            Node *left_head = head;
            Node *right_head = middle->next;
            
            middle->next = nullptr;
            
            left_head = sort_ll(left_head);
            right_head = sort_ll(right_head);

            return merge(left_head, right_head);
        }
};