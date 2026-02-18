#include <iostream>

using namespace std;

// Time Complexity O(logn)

int binary_search(int A[], int n, int x) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (x == A[mid]) return mid;
        else if (x < A[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main () {
    int A[] = {5, 9, 12, 16, 21};

    int result = binary_search(A, 5, 22);

    cout << "The value lies at index position " << result;

    return 0;
}