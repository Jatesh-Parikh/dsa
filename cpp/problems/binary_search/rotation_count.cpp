// # of rotations = index of min element
#include<iostream>

using namespace std;

int rotation_count(int A[], int n) {
    int low = 0;
    int high = n - 1;
    while(low <= high) {
        if (A[low] <= A[high]) {
            return low;
        }

        int mid = low + (high - low) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) %n; 

        if (A[mid] <= A[next] && A[mid] <= A[prev]) {
            return mid; // the pivot element
        } else if (A[mid] <= A[high]) {
            high = mid - 1;
        } else if (A[mid] >= A[low]) {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    int A[] = {15, 22, 23, 28, 31, 38, 5, 6, 8, 10, 12};

    int count = rotation_count(A, 11);

    if(count != -1) {
        cout << "The rotation count is: " << count;
    } else {
        cout << "Invalid array";
    }

    return 0;
}