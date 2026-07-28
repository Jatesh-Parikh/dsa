#include <iostream>
#include <vector>

using namespace std;

// Time Complexity - O(sqrt(n))
// Space Complexity - O(1)
vector<int> prime_factors(int n) {
    vector<int> ans;

    while (n % 2 == 0) {
        ans.push_back(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
    }

    if (n > 1) ans.push_back(n);

    return ans;
}

int main () {   
    int n;

    cin >> n;

    vector<int> factors = prime_factors(n);

    for (auto it: factors) cout << it << " ";
    cout << endl;

    return 0;
}