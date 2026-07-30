#include <vector>
#include <iostream>

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

        // Time Complexity - O(n)
        // Space Complexity - O(1)
        void traverse(vector<int>& arr) {
            Node *head = convert_arr_to_ll(arr);
            Node *temp = head;
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }

        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int length_of_ll(Node *head) {
            int count = 0;
            Node *temp = head;

            while (temp) {
                count++;
                temp = temp->next;
            }

            return count;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(1)
        bool search(Node *head, int x) {
            Node *temp = head;

            while (temp) {
                if (temp->data == x) return true;
                temp = temp->next;
            }

            return false;
        }
};