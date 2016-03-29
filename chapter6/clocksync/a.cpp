#include <bits/stdc++.h>
using namespace std;

string sw[10] = {
  "xxx.............",
  "...x...x.x.x....",
  "....x.....x...xx",
  "x...xxxx........",
  "......xxx.x.x...",
  "x.x...........xx",
  "...x..........xx",
  "....xx.x......xx",
  ".xxxxx..........",
  "...xxx...x...x.."
};

int converter(int x) {
  if(x ==12) return 0;
  if(x==3) return 1;
  if(x==6) return 2;
  if(x==9) return 3;
}

void click(int sn, vector<int> & vec) {
  for(int i=0; i<16; i++) {
    if ( sw[sn][i] =='x') {
      vec[i] += 1;
      vec[i] %= 4;
    }
  }
}

int main() {
  int c;
  cin >> c;
  while(c--) {
    vector<int> cur = vector<int>(16,0);
    for(int i=0; i<16; i++){
      int x;
      cin >> x;
      cur[i] = converter(x);
    } 
    int ret = 500;
    for(int i=0;i<1024 * 1024; i++) {
      vector<int> clicks;
      vector<int> tmp = cur;
      int x = i;
      for(int j=0; j<16; j++) {
        int y = x % 4;
        for(int k=0; k< y; k++)
          clicks.push_back(j);
        x = x / 4;
      }
      for(int j=0;j<clicks.size(); j++) {
        click(clicks[j], tmp);
      }
      bool z = true;
      for(int j=0; j< 16; j++) {
        if(tmp[j] != 0) {
          z = false;
          break;
        }
      }
      if(z) ret = min(ret , (int)clicks.size()); 
    }
    if ( ret > 100) cout << -1 << endl;
    else cout << ret << endl;
  }

  return 0;
}