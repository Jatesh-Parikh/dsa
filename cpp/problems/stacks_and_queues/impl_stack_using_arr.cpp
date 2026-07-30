#include <iostream>

using namespace std;

class Stack {
    private:
        static const int MAX = 1000;
        int arr[MAX];
        int top_index;
    
    public:
        Stack() {
            top_index = -1;
        }

        void push(int value) {
            if (top_index == MAX - 1) {
                cout << "Stack overflow" << endl;
                return;
            }
            arr[++top_index] = value;
        }

        void pop() {
            if (is_empty()) {
                cout << "Stack underflow" << endl;
                return;
            }
            top_index--;
        }

        int top() {
            if (is_empty()) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return arr[top_index];
        }

        int size() {
            return top_index + 1;
        }

        bool is_empty() {
            return top_index == -1;
        }
};