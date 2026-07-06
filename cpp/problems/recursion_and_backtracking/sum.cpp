// Parametrized Recursion 
// 1. You pass the answer built so far as a parameter
// 2. The recursive function typically returns void
// 3. The base case simply uses the accumulated parameter and prints or stores it

// Functional Recursion
// 1. You don't carry the answer as a parameter
// 2. Each recursive call returns a value, and the caller combines it with it's own work

#include <iostream>

using namespace std;

void parameterized_sum(int i, int sum) {
    if (i <= 0) {
        cout << sum << endl;
        return;
    }

    parameterized_sum(i - 1, sum + i);
}

int functional_sum(int i) {
    if (i <= 0) {
        return 0;
    }
    return i + functional_sum(i - 1);
}

int main () {
    int n = 5;
    parameterized_sum(n, 0);
    cout << functional_sum(n) << endl;
    return 0;
}