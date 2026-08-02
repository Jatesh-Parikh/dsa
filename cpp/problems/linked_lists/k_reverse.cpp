struct Node {
    int data;
    Node *next;

    Node(): data(0), next(nullptr) {}
    Node(int data): data(data), next(nullptr) {}
    Node(int data, Node *next): data(data), next(next) {}
};

class Solution {
    private:
        Node *reverse(Node *head) {
            Node *temp = head;
            Node *prev = nullptr;
            
            while (temp) {
                Node *front = temp->next;
                temp->next = prev;
                prev = temp;
                temp = front;
            }

            return prev;
        }

        Node *get_kth_node(Node *head, int k) {
            k -= 1;
            Node *temp = head;

            while (temp && k > 0) {
                k--;
                temp = temp->next;
            }

            return temp;
        }

    public:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        Node *k_reverse(Node *head, int k) {
            Node *temp = head;
            Node *prev_node = nullptr;

            while (temp) {
                Node *kth_node = get_kth_node(temp, k);

                if (kth_node == nullptr) {
                    if (prev_node) prev_node->next = temp;
                    break;
                }

                Node *next_node = kth_node->next;
                kth_node->next = nullptr;

                Node *new_head = reverse(temp);

                if (temp == head) {
                    head = new_head;
                } else {
                    prev_node->next = new_head;
                }

                prev_node = temp;
                temp = next_node;
            }

            return head;
        }
};