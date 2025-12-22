#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Station {
    int p, c;
};

bool compareStations(const Station& a, const Station& b) {
    return a.p < b.p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    long long x;
    cin >> n >> m >> x;

    vector<Station> stations(n);
    for (int i = 0; i < n; ++i) {
        cin >> stations[i].p >> stations[i].c;
    }
    sort(stations.begin(), stations.end(), compareStations);

    vector<long long> w(m);
    long long total_constant = 0;
    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        w[i] = a - b;
        total_constant += 2 * b * x;
    }
    sort(w.begin(), w.end(), greater<long long>());

    long long min_dynamic = 0;
    int station_idx = 0;
    for (int i = 0; i < m; ++i) {
        while (stations[station_idx].c == 0) {
            station_idx++;
        }
        min_dynamic += 2LL * stations[station_idx].p * w[i];
        stations[station_idx].c--;
    }

    cout << min_dynamic + total_constant << endl;

    return 0;
}