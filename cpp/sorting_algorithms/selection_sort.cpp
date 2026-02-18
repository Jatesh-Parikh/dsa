#include<iostream>
using namespace std;

// Time Complexity O(n^2)

void selection_sort(int A[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int iMin = i;
        for (int j = i + 1; j < n; j++) {
            if(A[j] < A[iMin]) {
                iMin = j; // update the index of the minimum element
            }
        }
        int temp = A[i];
        A[i] = A[iMin];
        A[iMin] = temp;
    }
}

int main () {
    int A[] = {2, 7, 4, 1, 5, 3};
    selection_sort(A, 6);

    cout << "Sorted Array: ";
    for (int i = 0; i < 6; i++) {
        cout << A[i] << " ";
    }

    return 0;
}

