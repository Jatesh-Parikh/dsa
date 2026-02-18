#include<iostream>
using namespace std;

// Time Complexity O(n^2)

void insertion_sort(int A[], int n) {
    for (int i = 1; i <= n - 1; i++) {
        int value = A[i];
        int hole = i;
        while (hole > 0 && A[hole - 1] > value) {
            A[hole] = A[hole - 1];
            hole = hole - 1;
        }
        A[hole] = value;
    }
}

int main () {
    int A[] = {2, 7, 4, 1, 5, 3};
    insertion_sort(A, 6);

    cout << "Sorted Array: ";
    for (int i = 0; i < 6; i++) {
        cout << A[i] << " ";
    }

    return 0;
}