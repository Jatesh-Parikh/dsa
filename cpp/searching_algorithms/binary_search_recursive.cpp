#include <iostream>

using namespace std;

// Time Complexity O(logn)

int binary_search_recursive(int A[], int low, int high, int x) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    if (x == A[mid]) return mid;
    else if (x < A[mid]) return binary_search_recursive(A, low, mid - 1, x);
    else return binary_search_recursive(A, mid + 1, high, x);
}

int main() {
    int A[] = {5, 9, 12, 16, 21};

    int result = binary_search_recursive(A, 0, 4, 18);

    if (result == -1) {
        cout << "Value not found";
    } else {
        cout << "The value lies at index position: " << result;
    }

    return 0;
}