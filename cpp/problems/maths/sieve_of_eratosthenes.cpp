// Given a number, print all the prime numbers till n

#include <iostream>
#include <vector>

using namespace std;

// Time Complexity - O(n * log logn)
// Space Complexity - O(1)
int main () {
    int n;

    cin >> n;

    if (n >= 2) cout << 2 << " ";

    vector<bool> prime(n + 1, true);

    for (int i = 3; i * i <= n; i += 2) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += 2 * i) {
                prime[j] = false;   
            }
        }
    }

    for (int i = 3; i <= n; i += 2) {
        if(prime[i]) cout << i << " ";
    }

    return 0;
}