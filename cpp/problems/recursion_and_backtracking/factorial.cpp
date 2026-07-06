#include <iostream>

using namespace std;

void parameterized_factorial(int n, int result) {
    if (n <= 1) {
        cout << result << endl;
        return;
    }

    parameterized_factorial(n - 1, n * result);
}

int functional_factorial(int n) {
    if (n <= 1) return 1;

    return n * functional_factorial(n - 1);
}

int main () {
    int n = 5;

    parameterized_factorial(n, 1);

    cout << functional_factorial(n) << endl;

    return 0;
}