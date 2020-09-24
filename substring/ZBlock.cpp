#include <bits/stdc++.h>

using namespace std;

vector<int> zBlock(string &text) {
    int n = text.size();
    vector<int> z_block(n);
    z_block[0] = -1;
    int l, r, k;

    l = r = 0;
    for (int i = 1; i < n; ++i) {
        if (i > r) {
            l = r = i;
            while (r < n && text[r - l] == text[r]) {
                r++;
            }
            z_block[i] = r - l;
            r--;
        } else {
            k = i - l;
            if (z_block[k] < r - i + 1)
                z_block[i] = z_block[k];
            else {
                l = i;
                while (r < n && text[r - l] == text[r]) {
                    r++;
                }
                z_block[i] = r - l;
                r--;
            }
        }
    }
    return z_block;
}

int strStr(string &text, string &pattern) {
    int n = pattern.size();
    if (n == 0)
        return 0;
    string str = pattern + '&' + text;
    vector<int> z_block = zBlock(str);
    for (int i = 0; i < z_block.size(); ++i) {
        if (z_block[i] == n)
            return i - n - 1;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string text = "wef";
    string pat = "";
    cout << strStr(text, pat) << "\n";
    return 0;
}