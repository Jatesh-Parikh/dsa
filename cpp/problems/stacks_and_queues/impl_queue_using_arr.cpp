#include <iostream>

using namespace std;

class Queue {
    private:
        static const int MAX = 1000;
        int arr[MAX];
        int front, rear;
        int count;

    public:
        Queue() {
            front = 0;
            rear = -1;
            count = 0;
        }

        void push(int x) {
            if (count == MAX) {
                cout << "Queue overflow" << endl;
                return;
            }

            rear = (rear + 1) % MAX;
            arr[rear] = x;
            count++;
        }

        void pop() {
            if (is_empty()) {
                cout << "Queue underflow" << endl;
                return;
            }

            front = (front + 1) % MAX;
            count--;
        }

        int top() {
            if (is_empty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }

            return arr[front];
        }

        int size() {
            return count;
        }

        bool is_empty() {
            return count == 0;
        }
};