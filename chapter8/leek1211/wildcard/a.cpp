#include<bits/stdc++.h>
using namespace std;

int C,n;
string w;

int dp[102][102];

int solve(const string& s, int si, int wi) {
  int & ret = dp[si][wi];
  if(ret!= -1) return ret;

  if(si == s.size()) {
    if(wi == w.size()) {
      return ret = 1;
    } else if (w[wi] == '*') {
      return ret = solve(s, si, wi + 1);
    } else {
      return ret = 0;
    }
  }
  if(wi == w.size()) {
    return ret = 0;
  }

  ret = 0;
  if(w[wi] == '?') {
    return ret = solve(s, si + 1, wi + 1);
  } else if (w[wi] == '*') {
    if(si < s.size()) {
      ret = solve(s, si+1, wi+1) | solve(s, si+1, wi);
    }
    ret = ret | solve(s, si, wi+1);
    return ret;
  } else {
    if(s[si] == w[wi]) return ret = solve(s, si+1, wi+1);
    else return ret = 0;
  }
}

int main() {

  cin >> C;
  while(C--) {

    cin >> w;
    cin >> n;
    vector<string> fs;
    for(int i=0; i < n; i++) {
      for(int j =0; j<102; j ++) {
        for(int k=0 ;k <102; k++) {
          dp[j][k] = -1;
        }
      }
      string ss;
      cin >> ss;
      if(solve(ss, 0, 0))
        fs.push_back(ss);
    }
    sort(fs.begin(), fs.end());
    for(int i =0; i<fs.size(); i++)
      cout << fs[i] << endl;
  }
  return 0;
}
