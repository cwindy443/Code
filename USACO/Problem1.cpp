#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, ElsieTypingMode;
    if (!(cin >> T >> ElsieTypingMode)) return 0;

    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        cout << "YES" << "\n";

        if (ElsieTypingMode == 1) {
            string t = "";
            t.resize(n);
            
            int last_val = (s[n - 1] == 'O' ? 1 : 0);
            t[n - 1] = s[n - 1];

            for (int i = n - 2; i >= 0; --i) {
                int curr_val = (s[i] == 'O' ? 1 : 0);
                int next_val = (s[i + 1] == 'O' ? 1 : 0);
                
                if (curr_val ^ next_val) {
                    t[i] = 'O';
                } else {
                    t[i] = 'M';
                }
            }
            cout << t << "\n";
        }
    }

    return 0;
}