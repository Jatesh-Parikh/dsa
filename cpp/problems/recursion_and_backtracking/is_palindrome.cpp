#include <iostream>

using namespace std;

bool is_palindrome(string& s, int i, int n) {
    if (i >= n / 2) return true;

    if (s[i] != s[n - i -1]) return false;

    return is_palindrome(s, i + 1, n);
}

int main() {
    string s = "madam";
    int n = s.size();

    cout << is_palindrome(s, 0, n) << endl;

    return 0;
}