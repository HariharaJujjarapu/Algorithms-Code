#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <climits>
#include <deque>
using namespace std;

bool denseSubstring(string &s, int k) {
    int n = s.length();

    if (k <= 0 || k > n)
        return false;

    int value = 0;
    for (int i = 0; i < k; i++) {
        value += (s[i] == '1') ? 1 : -1;
    }
    if (value > 0)
        return true;

    for (int i = k; i < n; i++) {
        value += (s[i] == '1') ? 1 : -1;
        value -= (s[i-k] == '1') ? 1 : -1;

        if (value > 0)
            return true;
    }

    return false;
}

int main() {
    string s = "10000101";
    int k = 3;
    if(denseSubstring(s, k))
        cout << "Dense Substring Found";
    else
        cout << "Dense Substring Not Found";
}