#include<bits/stdc++.h>
using namespace std;

int c, n;
vector<int> sticks;

int greedyMid(int t, int f, int mid) {
  int mx = sticks[mid];
  int ret = mx;
  int cnt = 1;
  int i =mid-1;
  int j = mid+1;
  while( i>=t || j < f ) {
    if(i >=t && j < f) {
      int ri = min(mx, sticks[j]) * ( cnt + 1);
      int li = min(mx, sticks[i]) * ( cnt + 1);
      
      if( li > ri) {
        mx = min(mx, sticks[i]);
        i--;
        cnt ++;
        ret = max(ret, li);
      } else {
        mx = min(mx, sticks[j]);
        j ++;
        cnt ++;
        ret = max(ret, ri);
      }
    } else if (i >= t) {
      int li = min(mx, sticks[i]) * ( cnt + 1);
      mx = min(mx, sticks[i]);
      i--;
      cnt ++;
      ret = max(ret, li);
    } else {
      int ri = min(mx, sticks[j]) * ( cnt + 1);
      mx = min(mx, sticks[j]);
      j ++;
      cnt ++;
      ret = max(ret, ri);
    }
  }
  return ret;
}

int check(int t, int f) {
  if(f - t <= 1) {
    return sticks[t];
  }
  int ri = check((t+f)/2, f);
  int li = check(t, (t+f)/2);
  int mid = (t+f)/2;
  int ret = max(max(ri,li), greedyMid(t,f,mid));
  return ret;
}

int main() {
  cin >> c;
  while (c --) {
    sticks.clear();
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
      int x;
      scanf("%d", &x);
      sticks.push_back(x);
    }
    int ret = check(0, n);
    cout << ret << endl;
  }
  return 0;
}