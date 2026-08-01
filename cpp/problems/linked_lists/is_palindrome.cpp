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

    public:
        // Time Complexity - O(n)
        // Time Complexity - O(1)
        bool is_palindrome(Node *head) {
            if (head == nullptr || head->next == nullptr) return true;

            Node *slow = head;
            Node *fast = head;

            while (fast->next != nullptr && fast->next->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }

            Node *new_head = reverse(slow->next);

            Node *first = head;
            Node *second = new_head;

            while (second) {
                if (first->data != second->data) {
                    reverse(new_head);
                    return false;
                }
                first = first->next;
                second = second->next;
            }

            reverse(new_head);
            return true;
        }
};