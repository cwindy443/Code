#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> parts;
    for (int i = 24; i >= 1; --i) {
        int power_of_2 = 1 << i; // 2^i
        if (n >= power_of_2) {
            parts.push_back(power_of_2);
            n -= power_of_2;
        }
    }

    for (size_t i = 0; i < parts.size(); ++i) {
        cout << parts[i] << (i == parts.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
