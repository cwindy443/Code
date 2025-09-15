#include <iostream>
#include <stack>
#include <string>
#define int unsigned long long

using namespace std;

signed main()
{
  int t;
  cin >> t;
  while (t--)
  {
    stack<int> st;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      string s;
      cin >> s;
      if (s == "push")
      {
        int x;
        cin >> x;
        st.push(x);
      }
      else if (s == "pop")
      {
        if (st.empty())
        {
          cout << "Empty" << endl;
        }
        else
        {
          st.pop();
        }
      }
      else if (s == "query")
      {
        if (st.empty())
          cout << "Anguei!" << endl;
        else
          cout << st.top() << endl;
      }
      else
      {
        cout << st.size() << endl;
      }
    }
  }
  return 0;
}
