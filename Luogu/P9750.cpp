#include <bits/stdc++.h>

using ll = long long;

ll gcd(ll a, ll b) {
    return std::gcd(a, b);
}

void print_rational(ll p, ll q) {
    if (p == 0) {
        std::cout << 0;
        return;
    }
    ll common = gcd(p, q);
    p /= common;
    q /= common;
    if (q < 0) {
        p = -p;
        q = -q;
    }
    if (q == 1) {
        std::cout << p;
    } else {
        std::cout << p << "/" << q;
    }
}

std::pair<ll, ll> simplify_sqrt(ll n) {
    ll d_sq_out = 1;
    while (n % 4 == 0) {
        d_sq_out *= 2;
        n /= 4;
    }
    for (ll i = 3; i * i <= n; i += 2) {
        while (n % (i * i) == 0) {
            d_sq_out *= i;
            n /= (i * i);
        }
    }
    return {d_sq_out, n};
}

void solve() {
    ll a, b, c;
    std::cin >> a >> b >> c;
    double delta = pow(b, 2) - 4 * a * c;
    if(delta < 0){
      std::cout << "NO" << std::endl;
      continue;
    }
    double x1, x2;
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);
    double x = std::max(x1, x2);

  } 
  return 0;
}