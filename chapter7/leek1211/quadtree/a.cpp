#include <bits/stdc++.h>
using namespace std;

int c;
int n;
string s;

string solve(string& tmp) {
  if(tmp.size() == 1 ) return tmp;
  vector<string> seg;
  int cur = 0;
  string ss = "";
  for(int i=0; i<tmp.size(); i++) {
    if(tmp[i] == 'x') {
      if(i!= 0) {
        if(ss == "") cur += 4;
        else cur += 3;
        ss += tmp[i];
      }
    } else if(tmp[i] =='w') {
      if(cur > 0) cur --;
      ss += tmp[i];
    } else {
      if(cur > 0) cur --;
      ss += tmp[i];
    }
    if(cur == 0 && ss != "") {
      seg.push_back(ss);
      ss = "";
    }
  }
  string seg1 = solve(seg[0]);
  string seg2 = solve(seg[1]);
  string seg3 = solve(seg[2]);
  string seg4 = solve(seg[3]);
  return "x" + seg3 + seg4 + seg1 + seg2;
}

int main() {
  cin >> c;
  while ( c--) {
    cin >> s;
    string ret = solve(s);
    cout << ret << endl;
  }
}