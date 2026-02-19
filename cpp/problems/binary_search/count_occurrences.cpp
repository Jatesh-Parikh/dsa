#include<iostream>

using namespace std;

int first_or_last_occurrence(int A[], int n, int x, bool search_first) {
    int low = 0;
    int high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if(x == A[mid]) {
            result = mid;
            if(search_first) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else if (x < A[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int A[] = {1, 1, 3, 3, 5, 5, 5, 5, 5, 9, 9, 11};

    int first_index = first_or_last_occurrence(A, 12, 5, true);
    int last_index = first_or_last_occurrence(A, 12, 5, false);

    if (first_index != -1 && last_index != -1) {
        cout << "The number of occurrences are: " << last_index - first_index + 1;
    } else {
        cout << "Value not found";
    }

    return 0;
}