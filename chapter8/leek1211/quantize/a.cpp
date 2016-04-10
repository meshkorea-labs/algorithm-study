#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int c, n, s;

ll dp[101][11];
vector<ll> a;
ll sq(ll x) { return x * x; }

long long solve(int idx, int cnt) {
  ll& ret = dp[idx][cnt];
  if (ret!= -1) return ret;

  if (idx == a.size()) return ret = 0;
  if (cnt == 0) return ret= 1e10;
  ll csum =0;
  ret = 1e10;
  for(int i=0; i+idx < a.size(); i++) {
    csum += a[i+idx];
    ll avg1 = csum / (i + 1);
    ll avg2 = avg1 + 1;
    ll seg1 = 0;
    for(int j =idx ; j<= idx + i; j++) {
      seg1 += sq(a[j] - avg1);
    }
    ll seg2 = 0;
    for(int j =idx ; j<= idx + i; j++) {
      seg2 += sq(a[j] - avg2);
    }
    ll seg = min(seg1, seg2);
    ret = min ( ret, seg + solve(i+idx +1, cnt-1));
  }
  return ret;
}

int main() {
  cin >> c;
  while( c-- ) {
    cin >> n >> s;
    a.clear();
    for(int i=0 ;i<101; i++)
      for(int j=0; j<11; j++)
          dp[i][j] = -1;
    for(int i=0; i<n; i++){
      ll x;
      cin >> x;
      a.push_back(x);
    }
    sort(a.begin(), a.end());
    ll ret = solve(0, s);

    cout << ret<< endl;
  }
}
