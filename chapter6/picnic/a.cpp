#include <bits/stdc++.h>
using namespace std;

int c,n,m;
int f[11][11];

int fac(int x) {
  int ret = 1;
  for(int i=1;i<=x; i++)
    ret *= i;
  return ret;
}

int count(int status) {
  int ret = 0;
  if(status == 0) return ret = 1;
  ret = 0;
  for(int i=0; i<n;i ++) {
    for(int j= i+1; j<n; j++) {
      int p1 = (1 << i);
      int p2 = (1 << j);
      if((status & p1) == 0) continue;
      if((status & p2) == 0) continue;
      if(!f[i][j]) continue;
      int newStat = status ^ p1 ^ p2;
      ret += count(newStat);
    }
  }
  
  return ret;
}

int main () {

  cin >> c;
  while (c--) {
    for(int i=0; i<11; i++)
      for(int j=0;j<11; j++)
        f[i][j] = 0;

    cin >> n >> m;

    for(int i=0; i<m; i++) {
      int x,y;
      cin >> x >> y;
      f[x][y] = 1;
      f[y][x] = 1;
    }
    cout << count((1 << n) -1) / fac(n/2) << endl;

  }

  return 0;
}