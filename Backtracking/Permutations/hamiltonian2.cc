#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;
typedef vector<bool> VB;

int n, m;
VVE v;

VE w;
VB u;


void f(int k, int j, int c){

  if(j == n){
    cout << w[0]+1;
    for(int i = 1; i < n; i++) cout << " " << w[i]+1;
    cout << endl;
    if(c < m) m = c;
    return;
  }
  for(int i = 0; i < n; i++){
    if((not u[i]) and v[k][i] != 0){
      u[i] = true;
      w[j] = i;
      f(i, j + 1 ,c + v[k][i]);
      u[i] = false;
    }
  }
}

int main(){
  cin >> n;
  m = 10000000;
  v = VVE(n,VE(n));
  w = VE(n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) cin >> v[i][j];
  }
  u = VB(n, false);


  w[0] = 0;
  u[0] = true;
  f(0,1,0);
  cout << "min: " << m << endl;

}
