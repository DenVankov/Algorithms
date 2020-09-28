#include <bits/stdc++.h>

using namespace std;

// Solution O(n^2)
// Matrix dp[n][n] initialize false except dp[i][i] = true
// Go to n and size of palindrome while s[j] == s[k]
// If found better len update mx
int max_palindrome(string &s) {
    int n = s.size();

    bool dp[n][n];

    // Initialize
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = false;
        }
    }
    // length == 1
    int mx = 1;
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    // length == 2
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            mx = 2;
        }
    }

    //length == 3+
    for (int i = 3; i <= n; ++i) {
        for (int j = 0; j < n - i + 1; ++j) {
            int k = j + i - 1;
            if (dp[j + 1][k - 1] && s[j] == s[k]) {
                dp[j][k] = true;
                mx = max(mx, i);
            }
        }
    }

    return mx;
}


// Linear solution
// Go on centers with odd and even size
// If even size take left idx = i - 1, right idx = i (center 2 letters)
// If odd size take left idx = i - 1, right idx = i + 1 (center 1 letter on i-th idx)
int max_on_palindrome(string &s) {
    int mx = 1;
    int n = s.size();

    int left, right;

    for (int i = 1; i < n; ++i) {

        // Even len
        left = i - 1;
        right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            mx = max(mx, right - left + 1);
            left--;
            right++;
        }

        //Odd len
        left = i - 1;
        right = i + 1;
        while(left >= 0 && right < n && s[left] == s[right]) {
            mx = max(mx, right - left + 1);
            left--;
            right++;
        }
    }

    return mx;
}

int main() {
    string s = "werfjabbbadlplabacdcwikffk";
    cout << max_palindrome(s) << "\n";
    cout << max_on_palindrome(s) << "\n";
    return 0;
}
