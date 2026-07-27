#include <iostream>

using namespace std;

// Time Complexity - O(sqrt(n))
// Space Complexity - O(1)
void print_divisors(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
            
            if (i != n / i) {
                cout << n / i << " ";
            }
        }
    }
}

int main() {
    int n;

    cin >> n;

    print_divisors(n);

    return 0;
}