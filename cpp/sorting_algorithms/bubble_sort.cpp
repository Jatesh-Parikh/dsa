#include<iostream>
using namespace std;

// Time Complexity O(n^2)

void bubble_sort(int A[], int n) {
    for (int k = 1; k <= n - 1; k++) {
        bool swap = false;

        for (int i = 0; i <= n - k - 1; i++) {
            if(A[i] > A[i + 1]) {
                int temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;

                swap = true;
            }
        }

        if(!swap) {
            break;
        }
    }
}

int main () {
    int A[] = {2, 7, 4, 1, 5, 3};
    bubble_sort(A, 6);

    cout << "Sorted Array: ";
    for (int i = 0; i < 6; i++) {
        cout << A[i] << " ";
    }

    return 0;
}