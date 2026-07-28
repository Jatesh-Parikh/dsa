#include <iostream>
#include <vector>

using namespace std;

// Time Complexity - O(r log log r)
// Space Complexity - O(r)
int count_primes(int l, int r) {
    if (r < 2) return 0;
    if (l < 2) l = 2;

    vector<bool> prime(r + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 4; i <= r; i+=2) prime[i] = false;

    for (int i = 3; i * i <= r; i+=2) {
        if (prime[i]) {
            for (int j = i * i; j <= r; j += 2 * i) prime[j] = false;
        }
    }
    // Every composite will be marked as false upto r 


    int count = 0;
    for (int i = l; i <= r; i++) {
        if (prime[i]) count++;
    }

    return count;
}

int main() {
    int l, r;
    cin >> l >> r;

    cout << count_primes(l, r) << endl;

    return 0;
}