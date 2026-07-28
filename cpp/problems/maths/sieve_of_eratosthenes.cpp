// Given a number, print all the prime numbers till n

#include <iostream>
#include <vector>

using namespace std;

// Time Complexity - O(n log log n)
// Space Complexity - O(n)
int main () {
    int n;

    cin >> n;

    if (n >= 2) cout << 2 << " ";

    vector<bool> prime(n + 1, true);

    for (int i = 3; i * i <= n; i += 2) { // We do not process even numbers
        if (prime[i]) {
            for (int j = i * i; j <= n; j += 2 * i) { // Every odd multiple <= n is marked as composite
                prime[j] = false;   
            }
        }
    }

    // Now all the composites <= n have been marked as false

    for (int i = 3; i <= n; i += 2) { // Looping through all the odd multiples to check if they are prime
        if(prime[i]) cout << i << " ";
    }

    return 0;
}