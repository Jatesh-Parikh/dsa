struct Node {
    int data;
    Node *next;

    Node(): data(0), next(nullptr) {}
    Node(int data): data(data), next(nullptr) {}
    Node(int data, Node *next): data(data), next(next) {}
};

class Solution {
    private:
        Node *find_kth_node(Node *head, int k) {
            int count = 1;
            Node *temp = head;

            while (temp) {
                if (count == k) break;
                count++;
                temp = temp->next;
            }

            return temp;
        }

    public:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        Node *rotate(Node *head, int k) {
            if (head == nullptr || k == 0) return head;

            int len = 1;
            Node *tail = head;
            
            while (tail->next) {
                len++;
                tail = tail->next;
            }

            if (k % len == 0) return head;
            else k = k % len;

            tail->next = head;

            Node *last_node = find_kth_node(head, len - k);
            
            head = last_node->next;
            last_node->next = nullptr;

            return head;
        }

};