#include <vector>

using namespace std;

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
        Node *convert_arr_to_ll(vector<int>& arr) {
            Node *head = new Node(arr[0]);
            Node * mover = head;

            for (int i = 1; i < arr.size(); i++) {
                Node *temp = new Node(arr[i]);
                mover->next = temp;
                mover = temp;
            }

            return head;
        }
};