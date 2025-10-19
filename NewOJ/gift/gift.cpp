#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;
int n, m, d;
int a[N], b[N];
bool cmp(int x, int y)
{
  return x > y;
}

signed main()
{
  freopen("gift.in", "r", stdin);
  freopen("gift.out", "w", stdout);

  cin >> n >> m >> d;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= m; i++)
    cin >> b[i];

  sort(a + 1, a + 1 + n, cmp);
  sort(b + 1, b + 1 + m, cmp);

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (abs(a[i] - b[j]) <= d)
      {
        cout << a[i] + b[j] << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;

  fclose(stdin);
  fclose(stdout);
  return 0;
}