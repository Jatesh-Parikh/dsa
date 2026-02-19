#include<iostream>

using namespace std;

int circular_array_search(int A[], int n, int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (x == A[mid]) {
            return mid;
        } else if (A[mid] <= A[high]) { // right half is sorted
            if (x > A[mid] && x <= A[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } else { // left half is sorted
            if (x >= A[low] && x < A[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }

    return -1;
}

int main() {
    int A[] = {15, 22, 23, 28, 31, 38, 5, 6, 8, 10, 12};

    int result = circular_array_search(A, 11, 5);

    if (result != -1) {
        cout << "The value lies at index position: " << result;
    } else {
        cout << "Value not found";
    }

    return 0;
}