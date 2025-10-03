#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;
int n, m;
int a[N];

bool check(int x) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += min(x, a[i]);
        if(sum > m) return false;
    }
    return true;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int total = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        total += a[i];
    }
    if(total <= m) {
        cout << "infinite" << endl;
        return 0;
    }
    int l = 0, r = 1e9, ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
