struct Node {
    int data;
    Node *next;

    Node(): data(0), next(nullptr) {}
    Node(int data): data(data), next(nullptr) {}
    Node(int data, Node *next): data(data), next(next) {}
};

class Solution {
    public:
        // Time Complexity - O(l1 + l2)
        // Space Complexity - O(1)
        Node *intersection(Node *first_head, Node *second_head) {
            if (first_head == nullptr || second_head == nullptr) return nullptr;
            Node *temp_1 = first_head;
            Node *temp_2 = second_head;

            while (temp_1 != temp_2) {
                temp_1 = temp_1->next;
                temp_2 = temp_2->next;

                if (temp_1 == temp_2) return temp_1;
                if (temp_1 == nullptr) temp_1 = second_head;
                if (temp_2 == nullptr) temp_2 = first_head;
            }

            return temp_1;
        }
};