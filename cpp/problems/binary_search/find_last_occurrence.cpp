#include<iostream>

using namespace std;

int find_last_occurrence(int A[], int n, int x) {
    int low = 0;
    int high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (x == A[mid]) {
            result = mid;
            low = mid + 1;
        } else if (x < A[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int A[] = {1, 4, 5, 6, 6, 6, 8, 9};

    int result = find_last_occurrence(A, 8, 6);

    if (result == -1) {
        cout << "Value not found";
    } else {
        cout << "The last occurrence is at index position: " << result; 
    }
    return 0;
}