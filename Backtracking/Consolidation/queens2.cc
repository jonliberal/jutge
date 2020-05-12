#include<iostream>
#include<vector>
using namespace std;

typedef vector<bool> VB;
typedef vector<VB> VVB;

VB d1,d2,d3,d4;
VVB v;


int n, s;


void f(int i){
  if(i == n){
    s += 1;
    for(int j = 0; j < n; j++){
      for(int k= 0; k < n; k++){
        if(v[j][k]) cout << 'Q';
        else cout << '.';
      }
      cout << endl;
    }
    cout << endl;
    return;
  }

  int j = i;
  for(int k = 0; k < n; k++){
    if(d1[j] and d2[k] and d3[j-k+n-1] and d4[j+k]){
      d1[j] = false;
      d2[k] = false;
      d3[j-k+n-1] = false;
      d4[j+k] = false;
      v[j][k] = true;
      f(i+1);
      v[j][k] = false;
      d1[j] = true;
      d2[k] = true;
      d3[j-k+n-1] = true;
      d4[j+k] = true;
    }
  }
}

int main(){
  cin >> n;
  s = 0;
  v = VVB(n, VB(n, false));
  d1 = VB(n, true);
  d2 = VB(n, true);
  d3 = VB(2 * n - 1, true);
  d4 = VB(2 * n - 1, true);
  f(0);
}
