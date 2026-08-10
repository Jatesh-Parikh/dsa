#include <vector>
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(): data(0), next(nullptr), prev(nullptr) {}
    Node(int data): data(data), next(nullptr),  prev(nullptr) {}
    Node(int data, Node *next): data(data), next(next),  prev(nullptr) {}
    Node(int data, Node *next, Node *prev): data(data), next(next), prev(prev) {}
};

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        Node *convert_arr_to_dll(vector<int>& arr) {
            if (arr.size() == 0) return nullptr;
            
            Node *head = new Node(arr[0]);
            Node *mover = head;

            for (int i = 1; i < arr.size(); i++) {
                Node *temp = new Node(arr[i]);
                mover->next = temp;
                temp->prev = mover;
                mover = temp;
            }

            return head;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(n)
        void traverse(vector<int>& arr) {
            Node *head = convert_arr_to_dll(arr);
            Node *temp = head;
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }

        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int length_of_dll(Node *head) {
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