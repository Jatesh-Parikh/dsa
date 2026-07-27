#include <iostream>

using namespace std;

// Time Complexity - O(logn)
// Space Complexity - O(1)
double power_exponentiation(int x, int n) {
    double ans = 1;
    int m = abs(n);
    
    while (m > 0) {
        if (m % 2 == 1) {
            ans = ans * x;
            m--;
        } else {
            m /= 2;
            x *= x;
        }
    }

    if (n < 0) ans = 1 / ans;

    return ans;
}

int main () {
    int x, n;

    cin >> x >> n;

    double ans = power_exponentiation(x, n);

    cout << ans << endl;

    return 0;
}